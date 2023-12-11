# REFERENCED: https://www.geeksforgeeks.org/mmouse-clicks-on-sprites-in-pygame/

import os
import pygame as pg
import math
from spritesheet import Spritesheet as Spritesheet

class Entity(pg.sprite.Sprite):
    def __init__(self, startLocation, team):
        super(Entity, self).__init__()
        
        # Initialize sprites to empty list
        self.__idleFrameSet = []
        self.__walkFrameSet = []
        self.__actionFrameSet = []
        self.__deathFrameSet = []
        
        # default spritesheet and animation frame variables
        self.frameNumber = 0        # current frame of animation
        self.width = 32         # width of each sprite on spritesheet
        self.height = 32        # height of each sprite on spritesheet
        
        startframe = 0
        endframe = 9          # group of frames in row to be loaded
        row = 0                 # row of spritesheet to look in
        self.addIdleFrameSet('./assets/warrior spritesheet calciumtrice.png', startframe, endframe, row, self.width, self.height)
        row = 1
        self.addIdleFrameSet('./assets/warrior spritesheet calciumtrice.png', startframe, endframe, row, self.width, self.height)
        row = 2
        self.addWalkFrameSet('./assets/warrior spritesheet calciumtrice.png', startframe, endframe, row, self.width, self.height)
        row = 3
        self.addActionFrameSet('./assets/warrior spritesheet calciumtrice.png', startframe, endframe, row, self.width, self.height)
        row = 4    
        self.addDeathFrameSet('./assets/warrior spritesheet calciumtrice.png', startframe, endframe, row, self.width, self.height)
        
        # default unit stats
        self.hp = 100
        self.speed = 100
        self.attackDamage = 10
        self.attackRange = 46
        self.unitType = 'melee'
        
        # default unit state variables
        self.team = team
        self.selected = False
        self.doing = 'idle'        # idle, walk, action, death
        self.inCombatWith = None
        self.dead = False
        self.location = startLocation
        self.destination = startLocation
        self.direction = 1          # 1 = Right, -1 = Left
        
        # default sprite and image creation
        startFrame = self.idleFrameSet[self.frameNumber]
        self.updateFrame(startFrame)
        
        
    # Properties
    
    # unit stat variables
    @property
    def hp(self):
        return self.__hp
    @hp.setter
    def hp(self, hp):
        if hp == None:
            raise ValueError("hp cannot be blank")
        if not isinstance(hp, int):
            raise ValueError("hp must be an integer")
        if hp <= 0:
            self.doing = 'death'
        self.__hp = hp
    @property
    def speed(self):
        return self.__speed
    @speed.setter
    def speed(self, speed):
        if speed == None:
            raise ValueError("speed cannot be blank")
        if not isinstance(speed, int):
            raise ValueError("speed must be an integer")
        if speed < 0:
            raise ValueError("speed cannot be negative")
        self.__speed = speed
    @property
    def attackDamage(self):
        return self.__attackDamage
    @attackDamage.setter
    def attackDamage(self, attackDamage):
        if attackDamage == None:
            raise ValueError("attackDamage cannot be blank")
        if not isinstance(attackDamage, int):
            raise ValueError("attackDamage must be an integer")
        if attackDamage < 0:
            raise ValueError("attackDamage cannot be negative")
        self.__attackDamage = attackDamage
    @property
    def attackRange(self):
        return self.__attackRange
    @attackRange.setter
    def attackRange(self, attackRange):
        if attackRange == None:
            raise ValueError("attackRange cannot be blank")
        if not isinstance(attackRange, int):
            raise ValueError("attackRange must be an integer")
        if attackRange < self.width or attackRange < self.height:
            raise ValueError("attackRange cannot be smaller than sprite width or height")
        self.__attackRange = attackRange
    @property
    def unitType(self):
        return self.__unitType
    @unitType.setter
    def unitType(self, unitType):
        if unitType == None:
            raise ValueError("unitType cannot be blank")
        if not isinstance(unitType, str):
            raise ValueError("unitType must be a string")
        if unitType not in ["melee", "ranged", "projectile"]:
            raise ValueError("unitType must be melee, ranged, or projectile")
        self.__unitType = unitType
        
    # unit state variables
    @property
    def team(self):
        return self.__team
    @team.setter
    def team(self, team):
        if team == None:
            raise ValueError("team cannot be blank")
        if not isinstance(team, str):
            raise ValueError("team must be a string")
        if team not in ['player', 'enemy']:
            raise ValueError("team must be 'player' or 'enemy'")
        self.__team = team
    @property
    def selected(self):
        return self.__selected
    @selected.setter
    def selected(self, selected):
        if selected == None:
            raise ValueError("selected cannot be blank")
        if not isinstance(selected, bool):
            raise ValueError("selected must be True or False")
        self.__selected = selected
    @property
    def doing(self):
        return self.__doing
    @doing.setter
    def doing(self, doing):
        if doing == None:
            raise ValueError("doing cannot be blank")
        if not isinstance(doing, str):
            raise ValueError("doing must be a string")
        if doing not in ['idle', 'walk', 'action', 'death']:
            raise ValueError("doing must be 'idle', 'walk', 'action', or 'death'")
        self.__doing = doing
    @property
    def inCombatWith(self):
        return self.__inCombatWith
    @inCombatWith.setter
    def inCombatWith(self, inCombatWith):
        if inCombatWith != None:
            if not isinstance(inCombatWith, Entity):
                raise ValueError("inCombatWith must be an Entity or None")
            if inCombatWith.unitType == 'projectile':
                raise ValueError("inCombatWith cannot be a projectile")
        self.__inCombatWith = inCombatWith
    @property
    def dead(self):
        return self.__dead
    @dead.setter
    def dead(self, dead):
        if dead == None:
            raise ValueError("dead cannot be blank")
        if not isinstance(dead, bool):
            raise ValueError("dead must be True or False")
        self.__dead = dead
    @property
    def location(self):
        return self.__location
    @location.setter
    def location(self, location):
        if location == None:
            raise ValueError("location cannot be blank")
        if not isinstance(location, tuple):
            raise ValueError("location must be a tuple")
        if location.__len__() != 2:
            raise ValueError("location must contain two integers")
        if not isinstance(location[0], int) or not isinstance(location[1], int):
            raise ValueError("location must contain two integers")
        self.__location = location
    @property
    def destination(self):
        return self.__destination
    @destination.setter
    def destination(self, destination):
        if destination == None:
            raise ValueError("destination cannot be blank")
        if not isinstance(destination, tuple):
            raise ValueError("destination must be a tuple")
        if destination.__len__() != 2:
            raise ValueError("destination must contain two integers")
        if not isinstance(destination[0], int) or not isinstance(destination[1], int):
            raise ValueError("destination must contain two integers")
        self.__destination = destination
    @property
    def direction(self):
        return self.__direction
    @direction.setter
    def direction(self, direction):
        if direction == None:
            raise ValueError("direction cannot be blank")
        if not isinstance(direction, int):
            raise ValueError("direction must be an integer")
        if direction not in [1, -1]:
            raise ValueError("direction must be 1 (Right) or -1 (Left)")
        self.__direction = direction
        
    # spritesheet and animation frame variables
    @property
    def frameNumber(self):
        return self.__frameNumber
    @frameNumber.setter
    def frameNumber(self, frameNumber):
        if frameNumber == None:
            raise ValueError("frameNumber cannot be blank")
        if not isinstance(frameNumber, int):
            raise ValueError("frameNumber must be an integer")
        if frameNumber < 0:
            raise ValueError("frameNumber cannot be negative")
        self.__frameNumber = frameNumber
    @property
    def width(self):
        return self.__width
    @width.setter
    def width(self, width):
        if width == None:
            raise ValueError("width cannot be blank")
        if not isinstance(width, int):
            raise ValueError("width must be an integer")
        if width <= 0:
            raise ValueError("width must be greater than 0")
        self.__width = width
    @property
    def height(self):
        return self.__height
    @height.setter
    def height(self, height):
        if height == None:
            raise ValueError("height cannot be blank")
        if not isinstance(height, int):
            raise ValueError("height must be an integer")
        if height <= 0:
            raise ValueError("height must be greater than 0")
        self.__height = height  
    @property
    def idleFrameSet(self):
        return self.__idleFrameSet
    @idleFrameSet.setter
    def idleFrameSet(self, idleFrameSet):
        if idleFrameSet == None:
            raise ValueError("idleFrameSet cannot be blank")
        if not isinstance(idleFrameSet, list):
            raise ValueError("idleFrameSet must be a list")
        self.__idleFrameSet = idleFrameSet
    @property
    def walkFrameSet(self):
        return self.__walkFrameSet
    @walkFrameSet.setter
    def walkFrameSet(self, walkFrameSet):
        if walkFrameSet == None:
            raise ValueError("walkFrameSet cannot be blank")
        if not isinstance(walkFrameSet, list):
            raise ValueError("walkFrameSet must be a list")
        self.__walkFrameSet = walkFrameSet
    @property
    def actionFrameSet(self):
        return self.__actionFrameSet
    @actionFrameSet.setter
    def actionFrameSet(self, actionFrameSet):
        if actionFrameSet == None:
            raise ValueError("actionFrameSet cannot be blank")
        if not isinstance(actionFrameSet, list):
            raise ValueError("actionFrameSet must be a list")
        self.__actionFrameSet = actionFrameSet
    @property
    def deathFrameSet(self):
        return self.__deathFrameSet
    @deathFrameSet.setter
    def deathFrameSet(self, deathFrameSet):
        if deathFrameSet == None:
            raise ValueError("deathFrameSet cannot be blank")
        if not isinstance(deathFrameSet, list):
            raise ValueError("deathFrameSet must be a list")
        self.__deathFrameSet = deathFrameSet
    
    def addIdleFrameSet(self, spritesheet, startframe, endframe, row, width, height):
        sprite_sheet_image = pg.image.load(spritesheet).convert_alpha()
        self.sprite_sheet = Spritesheet(sprite_sheet_image)
        for i in range(startframe, endframe):
            frame = self.sprite_sheet.get_image(i, row, width, height, (0, 0, 0))
            self.__idleFrameSet.append(frame)
            
    def addWalkFrameSet(self, spritesheet, startframe, endframe, row, width, height):
        sprite_sheet_image = pg.image.load(spritesheet).convert_alpha()
        self.sprite_sheet = Spritesheet(sprite_sheet_image)
        for i in range(startframe, endframe):
            frame = self.sprite_sheet.get_image(i, row, width, height, (0, 0, 0))
            self.__walkFrameSet.append(frame)
    def addActionFrameSet(self, spritesheet, startframe, endframe, row, width, height):
        sprite_sheet_image = pg.image.load(spritesheet).convert_alpha()
        self.sprite_sheet = Spritesheet(sprite_sheet_image)
        for i in range(startframe, endframe):
            frame = self.sprite_sheet.get_image(i, row, width, height, (0, 0, 0))
            self.__actionFrameSet.append(frame)
    def addDeathFrameSet(self, spritesheet, startframe, endframe, row, width, height):
        sprite_sheet_image = pg.image.load(spritesheet).convert_alpha()
        self.sprite_sheet = Spritesheet(sprite_sheet_image)
        for i in range(startframe, endframe):
            frame = self.sprite_sheet.get_image(i, row, width, height, (0, 0, 0))
            self.__deathFrameSet.append(frame)
    
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
                self.kill()
                if self.team == 'enemy':
                    return 100
                return 0
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
        return 0
        
    def attack(self, entity, delta):
        if entity.doing == 'death':
            self.inCombatWith = None
            self.idle()
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
              
                self.moveToAggro(entity.location[0], entity.location[1])
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
            
            #if self.unitType != 'ranged':
            entity.hp -= self.attackDamage
           
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
                self.walkAggro()
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
                # Collision detection (x-axis)
                for entity in entities:
                    if entity != self and entity.unitType != 'projectile':
                        if pg.sprite.collide_rect(self, entity):
                            self.rect.centerx -= directionX * self.speed * delta
                
                self.rect.centery += directionY * self.speed * delta
                # Collision detection (y-axis)
                for entity in entities:
                    if entity != self and entity.unitType != 'projectile':
                        if pg.sprite.collide_rect(self, entity):
                            self.rect.centery -= directionY * self.speed * delta
            # not sure this does anything                
            else:
                self.idle()
        else:
            if self.doing == 'walk':
                self.idle()
        self.location = (self.rect.centerx, self.rect.centery)
        
        # Aggro range
        if self.inCombatWith == None: #and self.selected == False:
            for entity in entities:
                if entity != self and entity.unitType != 'projectile':
                    if entity.doing != 'death':
                        if entity.team != self.team:
                            xDiff = self.location[0] - entity.location[0]
                            yDiff = self.location[1] - entity.location[1]
                            distance = math.sqrt(xDiff**2 + yDiff**2)
                            if self.unitType == 'ranged':
                                if distance <= self.attackRange*1.5:
                                    self.attack(entity, delta)
                                    break
                            # based off of smallest sprite size
                            # otherwise goblin will aggro from
                            # the other side of the solar system
                            if distance <= 32*6:
                                self.attack(entity, delta)
                                break
        
                    
        
        
        
        
        
        
            
        
