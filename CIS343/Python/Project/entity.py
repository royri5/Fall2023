# REFERENCED: https://www.geeksforgeeks.org/mmouse-clicks-on-sprites-in-pygame/

import os
import pygame as pg
import math
from spritesheet import Spritesheet as Spritesheet

class Entity(pg.sprite.Sprite):
    def __init__(self, startLocation):
        super(Entity, self).__init__()
        
        # TODO:
        # implement default sprite
        # allow child classes to override sprites
        #sprite_sheet_image = pg.image.load('./assets/warrior spritesheet calciumtrice.png').convert_alpha()
        #self.sprite_sheet = Spritesheet(sprite_sheet_image)
        self.idleFrameSet = []
        self.walkFrameSet = []
        self.actionFrameSet = []
        self.deathFrameSet = []
        self.frameNumber = 0
        self.setIdleFrameSet('./assets/warrior spritesheet calciumtrice.png', 9, 0, 32, 32)
        self.setIdleFrameSet('./assets/warrior spritesheet calciumtrice.png', 9, 1, 32, 32)
        self.setWalkFrameSet('./assets/warrior spritesheet calciumtrice.png', 9, 2, 32, 32)
        self.setActionFrameSet('./assets/warrior spritesheet calciumtrice.png', 9, 3, 32, 32)
        self.setDeathFrameSet('./assets/warrior spritesheet calciumtrice.png', 9, 4, 32, 32)
        #startFrame = self.sprite_sheet.get_image(3, 4, 32, 32, (0, 0, 0))
        startFrame = self.idleFrameSet[self.frameNumber]
        self.doing = 'idle'        # idle, walk, action, death
        self.animationFramerate = 10
        
        
        # add 10 frames to the idle frame set
        
        self.location = startLocation
        self.destination = startLocation
        self.isMoving = False
        self.direction = 1          # 1 = Right, -1 = Left
        self.updateFrame(startFrame)
        #self.callback = callback
        self.selected = False
        self.team = 'player'
        self.speed = 100
        self.type = 'melee'
    
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
        else:
            #error
            pass
        self.rect = self.image.get_rect()
        self.rect.centerx = self.location[0]
        self.rect.centery = self.location[1]
    
    def updateAnimation(self): 
        if self.doing == 'idle':
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
        
    def draw(self, screen):
        screen.blit(self.image, self.rect)

    # head towards location until you reach it
    # or until you run into the game border
    def moveTo(self, x, y):
        self.isMoving = True
        self.doing = 'walk'
        self.destination = (x, y)
        
    # "AI" movement
    # make sure it works for all 4 directions (might need abs())
    def update(self, delta):
        # update location
        # GPT ASSISTED
        
        if self.destination != self.location:
            xDiff = self.destination[0] - self.location[0]
            yDiff = self.destination[1] - self.location[1]
            distance = math.sqrt(xDiff**2 + yDiff**2)
            if distance > 1:
                directionX = xDiff / distance
                directionY = yDiff / distance
                # direction faced is based on direction of movement
                if directionX > 0:
                    self.direction = 1
                else:
                    self.direction = -1
                
                self.rect.centerx += directionX * self.speed * delta
                self.rect.centery += directionY * self.speed * delta
            else:
                self.isMoving = False
                self.doing = 'idle'  
        else:
            if self.isMoving == True:
                self.isMoving = False
                self.doing = 'idle'
            
        self.location = (self.rect.centerx, self.rect.centery)
        
        # update frame (idle)
        # use delta to determine how long to wait before updating frame
        
        
        
        
        
        # elif self.doing == 'death':
        #     if self.frameNumber < self.deathFrameSet.__len__() - 1:
        #         self.frameNumber += 1
        #     else:
        #         self.frameNumber = 0
        #     self.updateFrame(self.deathFrameSet[self.frameNumber])
            
        
