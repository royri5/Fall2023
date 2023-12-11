
import pygame as pg
from entity import Entity as Entity
import math

class Ranged(Entity):
    def __init__(self, startLocation, team):
        super().__init__(startLocation, team)
        self.idleFrameSet = []
        self.walkFrameSet = []
        self.actionFrameSet = []
        self.deathFrameSet = []
        self.frameNumber = 0
        self.unitType = 'ranged'
        self.attackRange = self.width * 3
        self.inRange = False
        
        if team == 'player':
            self.width = 32
            self.height = 32
            self.attackRange = 130
            
            startframe = 0
            endframe = 10
            row = 0
            self.addIdleFrameSet('./assets/ranger spritesheet calciumtrice.png', startframe, endframe, row, self.width, self.height)
            row = 1
            self.addIdleFrameSet('./assets/ranger spritesheet calciumtrice.png', startframe, endframe, row, self.width, self.height)
            row = 2
            self.addWalkFrameSet('./assets/ranger spritesheet calciumtrice.png', startframe, endframe, row, self.width, self.height)
            row = 3
            self.addActionFrameSet('./assets/ranger spritesheet calciumtrice.png', startframe, endframe, row, self.width, self.height)
            row = 4    
            self.addDeathFrameSet('./assets/ranger spritesheet calciumtrice.png', startframe, endframe, row, self.width, self.height)
        elif team == 'enemy':
            # print test
            self.width = 32
            self.height = 32
            self.attackRange = 130
            
            # ghost sprite sheet does not have as many idle frames as ranger
            # so we will have to add the same frame multiple times to make it look
            # uniform
            
            # frame group idle
            #startframe = 0
            #endframe = 3
            startframe = 0
            endframe = 1
            row = 2
            self.addIdleFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            self.addIdleFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            startframe = 1
            endframe = 2
            self.addIdleFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            self.addIdleFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            startframe = 2
            endframe = 3
            self.addIdleFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            self.addIdleFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            startframe = 3
            endframe = 4
            self.addIdleFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            self.addIdleFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            
            # frame group walk
            # startframe = 0
            # endframe = 5
            startframe = 0
            endframe = 1
            row = 2
            self.addWalkFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            startframe = 1
            endframe = 2
            self.addWalkFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            startframe = 2
            endframe = 3
            self.addWalkFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            startframe = 3
            endframe = 4
            self.addWalkFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            
            # frame group action
            #startframe = 0
            #endframe = 5
            startframe = 0
            endframe = 1
            row = 1
            self.addActionFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            startframe = 1
            endframe = 2
            self.addActionFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            self.addActionFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            self.addActionFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            startframe = 2
            endframe = 3
            self.addActionFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            self.addActionFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            startframe = 3
            endframe = 4
            self.addActionFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            startframe = 4
            endframe = 5
            self.addActionFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            startframe = 5
            endframe = 6
            self.addActionFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            
            # frame group death
            #startframe = 0
            #endframe = 8
            startframe = 0
            endframe = 1
            row = 0
            self.addDeathFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            startframe = 1
            endframe = 2
            self.addDeathFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            startframe = 2
            endframe = 3
            self.addDeathFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            startframe = 3
            endframe = 4
            self.addDeathFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            startframe = 4
            endframe = 5
            self.addDeathFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            startframe = 5
            endframe = 6
            self.addDeathFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            startframe = 6
            endframe = 7
            self.addDeathFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            startframe = 7
            endframe = 8
            self.addDeathFrameSet('./assets/ghostIce_all.png', startframe, endframe, row, self.width, self.height)
            
        
        startFrame = self.idleFrameSet[self.frameNumber]
        self.updateFrame(startFrame)
        
    @property
    def inRange(self):
        return self.__inRange
    @inRange.setter
    def inRange(self, value):
        if value not in [True, False]:
            raise ValueError('inRange must be True or False')
        self.__inRange = value
        
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
                self.inRange = False
                self.moveToAggro(entity.location[0], entity.location[1])
                return
            else:
                self.inRange = True
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
            #    entity.hp -= self.attackDamage
           
            # Death setup
            if entity.hp <= 0:
                entity.death()
                self.idle()