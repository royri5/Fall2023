# REFERENCED: https://www.geeksforgeeks.org/mmouse-clicks-on-sprites-in-pygame/

import os
import pygame as pg
import math
from spritesheet import Spritesheet as Spritesheet

class Entity(pg.sprite.Sprite):
    def __init__(self, startLocation, team):
        super(Entity, self).__init__()
        
        # TODO:
        # implement default sprite
        # allow child classes to override sprites
        self.idleFrameSet = []
        self.walkFrameSet = []
        self.actionFrameSet = []
        self.deathFrameSet = []
        self.frameNumber = 0
        self.width = 32
        self.height = 32
        self.frameRange = 9
        self.row = 0
        self.setIdleFrameSet('./assets/warrior spritesheet calciumtrice.png', self.frameRange, self.row, self.width, self.height)
        self.row = 1
        self.setIdleFrameSet('./assets/warrior spritesheet calciumtrice.png', self.frameRange, self.row, self.width, self.height)
        self.row = 2
        self.setWalkFrameSet('./assets/warrior spritesheet calciumtrice.png', self.frameRange, self.row, self.width, self.height)
        self.row = 3
        self.setActionFrameSet('./assets/warrior spritesheet calciumtrice.png', self.frameRange, self.row, self.width, self.height)
        self.row = 4    
        self.setDeathFrameSet('./assets/warrior spritesheet calciumtrice.png', self.frameRange, self.row, self.width, self.height)
        
        #startFrame = self.sprite_sheet.get_image(3, 4, 32, 32, (0, 0, 0))
        startFrame = self.idleFrameSet[self.frameNumber]
        self.doing = 'idle'        # idle, walk, action, death
        self.animationFramerate = 10
        self.inCombatWith = None
        self.dead = False
        
        
        # add 10 frames to the idle frame set
        
        self.location = startLocation
        self.destination = startLocation
        self.direction = 1          # 1 = Right, -1 = Left
        self.updateFrame(startFrame)
        self.selected = False
        self.team = team
        self.speed = 100
        self.type = 'melee'
        self.hp = 100
        self.attackDamage = 10
        self.attackRange = 46
    
    def setIdleFrameSet(self, spritesheet, framerange, row, width, height):
        sprite_sheet_image = pg.image.load(spritesheet).convert_alpha()
        self.sprite_sheet = Spritesheet(sprite_sheet_image)
        for i in range(framerange):
            frame = self.sprite_sheet.get_image(i, row, width, height, (0, 0, 0))
            self.idleFrameSet.append(frame)
    def setWalkFrameSet(self, spritesheet, framerange, row, width, height):
        sprite_sheet_image = pg.image.load(spritesheet).convert_alpha()
        self.sprite_sheet = Spritesheet(sprite_sheet_image)
        for i in range(framerange):
            frame = self.sprite_sheet.get_image(i, row, width, height, (0, 0, 0))
            self.walkFrameSet.append(frame)
    def setActionFrameSet(self, spritesheet, framerange, row, width, height):
        sprite_sheet_image = pg.image.load(spritesheet).convert_alpha()
        self.sprite_sheet = Spritesheet(sprite_sheet_image)
        for i in range(framerange):
            frame = self.sprite_sheet.get_image(i, row, width, height, (0, 0, 0))
            self.actionFrameSet.append(frame)
    def setDeathFrameSet(self, spritesheet, framerange, row, width, height):
        sprite_sheet_image = pg.image.load(spritesheet).convert_alpha()
        self.sprite_sheet = Spritesheet(sprite_sheet_image)
        for i in range(framerange):
            frame = self.sprite_sheet.get_image(i, row, width, height, (0, 0, 0))
            self.deathFrameSet.append(frame)
    
    # when calling, update location
    def updateFrame(self, frame):
        # Direction of sprite is based on direction of prev or cur movement
        if self.direction == 1:
            self.image = frame
        elif self.direction == -1:
            self.image = pg.transform.flip(frame, True, False).convert_alpha()
        self.rect = self.image.get_rect()
        self.rect.centerx = self.location[0]
        self.rect.centery = self.location[1]
    
    def updateAnimation(self):
        if self.doing == 'death':
            if self.frameNumber < self.deathFrameSet.__len__() - 1:
                self.frameNumber += 1
            else:
                self.dead = True
                # TODO:
                # implement score
                self.kill()
            self.updateFrame(self.deathFrameSet[self.frameNumber])
        elif self.doing == 'idle':
            if self.frameNumber < self.idleFrameSet.__len__() - 1:
                self.frameNumber += 1
            else:
                self.frameNumber = 0
            self.updateFrame(self.idleFrameSet[self.frameNumber])
        elif self.doing == 'walk':
            if self.frameNumber < self.walkFrameSet.__len__() - 1:
                self.frameNumber += 1
            else:
                self.frameNumber = 0
            self.updateFrame(self.walkFrameSet[self.frameNumber])
        elif self.doing == 'action':
            if self.frameNumber < self.actionFrameSet.__len__() - 1:
                self.frameNumber += 1
            else:
                self.frameNumber = 0
            self.updateFrame(self.actionFrameSet[self.frameNumber])
        
    def attack(self, entity, delta):
        if entity.doing == 'death':
            self.inCombatWith = None
            return
        if entity.team != self.team:
            # Range check
            xDiff = self.location[0] - entity.location[0]
            yDiff = self.location[1] - entity.location[1]
            distance = math.sqrt(xDiff**2 + yDiff**2)
            
            # Move in range
            if distance > self.attackRange:
                # no longer in combat
                # moving towards entity loc
                # to trigger aggro 
                if self.selected == False:
                    self.moveToAggro(entity.location[0], entity.location[1])
                    self.inCombatWith = entity
                else: 
                    self.moveTo(entity.location[0], entity.location[1])
                    self.inCombatWith = entity
                return
            # face each other when attacking
            if entity.inCombatWith == None or entity.inCombatWith == self:
                entity.inCombatWith = self
                if self.direction == 1:
                    entity.direction = -1
                else:
                    entity.direction = 1
            self.action()
            self.inCombatWith = entity
            
            if self.type != 'ranged':
                entity.hp -= self.attackDamage
           # else:
                # TODO:
                # implement ranged attack
                # with projectiles
            #    pass
            # Death setup
            if entity.hp <= 0:
                entity.death()
                self.idle()
        
    def draw(self, screen):
        screen.blit(self.image, self.rect)

    def aniSwap(self):
        self.frameNumber = 0
        self.destination = self.location
    # head towards location until you reach it
    # or until you run into another unit
    def walk(self):
        if self.doing != 'walk':
            self.doing = 'walk'
            self.frameNumber = 0
        self.inCombatWith = None
    def walkAggro(self):
        if self.doing != 'walk':
            self.doing = 'walk'
            self.frameNumber = 0
    def idle(self):
        if self.doing != 'idle':
            self.doing = 'idle'
            self.aniSwap()
        self.inCombatWith = None
    def action(self):
        if self.doing != 'action':
            self.doing = 'action'
            self.aniSwap()
    def death(self):
        if self.doing != 'death':
            self.doing = 'death'
            self.aniSwap()
        self.inCombatWith = None
    def moveTo(self, x, y):
        self.walk()
        self.destination = (x, y)
    def moveToAggro(self, x, y):
        self.walkAggro()
        self.destination = (x, y)
    
            
    # "AI" movement
    def update(self, entities, delta):
        # update location
        # GPT ASSISTED
        
        if self.doing == 'death':
            return
        if self.hp <= 0:
            self.death()
            return
        if self.doing == 'action':
            if self.inCombatWith == None or self.inCombatWith.doing == 'death':
                self.idle()
                return
        
        
        # movement
        if self.destination != self.location:
            if self.doing != 'walk':
                self.walk()
            xDiff = self.destination[0] - self.location[0]
            yDiff = self.destination[1] - self.location[1]
            distance = math.sqrt(xDiff**2 + yDiff**2)
            if distance > 10:
                directionX = xDiff / distance
                directionY = yDiff / distance
                # direction faced is based on direction of movement
                if directionX > 0:
                    self.direction = 1
                else:
                    self.direction = -1
                self.rect.centerx += directionX * self.speed * delta
                self.rect.centery += directionY * self.speed * delta
                # Collision detection
                for entity in entities:
                    if entity != self:
                        if pg.sprite.collide_rect(self, entity):
                                # auto engage in combat
                            self.rect.centerx -= directionX * self.speed * delta
                            self.rect.centery -= directionY * self.speed * delta
                                
                            
            else:
                self.idle()
        else:
            if self.doing == 'walk':
                self.idle()
        self.location = (self.rect.centerx, self.rect.centery)
        
        # Aggro range
        if self.inCombatWith == None and self.selected == False:
            for entity in entities:
                if entity != self:
                    if entity.doing != 'death':
                        if entity.team != self.team:
                            xDiff = self.location[0] - entity.location[0]
                            yDiff = self.location[1] - entity.location[1]
                            distance = math.sqrt(xDiff**2 + yDiff**2)
                            if distance <= self.attackRange*6:
                                self.attack(entity, delta)
                                break
        
                    
        
        
        
        
        
        
            
        
