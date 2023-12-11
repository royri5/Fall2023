
import pygame as pg
from entity import Entity as Entity
import math

class Projectile(Entity):
    def __init__(self, startLocation, target):
        super().__init__(startLocation, 'player')
        self.idleFrameSet = []
        self.walkFrameSet = []
        self.actionFrameSet = []
        self.deathFrameSet = []
        self.frameNumber = 0
        self.unitType = 'projectile'
        self.speed = 300
        self.target = target
        #self.attackRange = self.width * 3
        
        self.width = 9
        self.height = 9
        #self.attackRange = 130
            
        startframe = 0
        endframe = 1
        row = 0
        self.addIdleFrameSet('./assets/circle_white.png', startframe, endframe, row, self.width, self.height)
        self.addIdleFrameSet('./assets/circle_white.png', startframe, endframe, row, self.width, self.height)
        row = 0
        self.addIdleFrameSet('./assets/circle_white.png', startframe, endframe, row, self.width, self.height)
        self.addIdleFrameSet('./assets/circle_white.png', startframe, endframe, row, self.width, self.height)
        row = 0
        self.addWalkFrameSet('./assets/circle_white.png', startframe, endframe, row, self.width, self.height)
        self.addIdleFrameSet('./assets/circle_white.png', startframe, endframe, row, self.width, self.height)
        row = 0
        self.addActionFrameSet('./assets/circle_white.png', startframe, endframe, row, self.width, self.height)
        self.addIdleFrameSet('./assets/circle_white.png', startframe, endframe, row, self.width, self.height)
        row = 0    
        self.addDeathFrameSet('./assets/circle_white.png', startframe, endframe, row, self.width, self.height)
        self.addIdleFrameSet('./assets/circle_white.png', startframe, endframe, row, self.width, self.height)
            
        
        startFrame = self.idleFrameSet[self.frameNumber]
        self.updateFrame(startFrame)
        self.moveTo(target.location[0], target.location[1])
    
    
    @property
    def target(self):
        return self.__target
    @target.setter
    def target(self, target):
        self.__target = target
        
    # ranged attacks
    # spawn projectile at attacker's location
    # projectile moves towards target
    # collides only with target
    # despawns on collision or after a set time(dies early)
    
    # modify moveTo here
    
    # modify attack in ranged
    
    # exempt projectile from entity functionality
    
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
                    if entity != self and entity == self.target:
                        if pg.sprite.collide_rect(self, entity):
                            #self.rect.centerx -= directionX * self.speed * delta
                            entity.hp -= self.attackDamage
                            self.death()
                
                self.rect.centery += directionY * self.speed * delta
                self.location = (self.rect.centerx, self.rect.centery)
                return
                # Collision detection (y-axis)
                for entity in entities:
                    if entity != self and entity == self.target:
                        if pg.sprite.collide_rect(self, entity):
                            #self.rect.centery -= directionY * self.speed * delta
                            entity.hp -= self.attackDamage
                            self.death()
            # not sure this does anything                
            else:
                self.idle()
        else:
            #if self.doing == 'walk':
            #    self.idle()
            self.kill()
        self.location = (self.rect.centerx, self.rect.centery)
        
        