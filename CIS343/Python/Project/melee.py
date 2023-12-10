
import pygame as pg
from entity import Entity as Entity

class Melee(Entity):
    def __init__(self, startLocation, team):
        super().__init__(startLocation, team)
        self.__idleFrameSet = []
        self.__walkFrameSet = []
        self.__actionFrameSet = []
        self.__deathFrameSet = []
        self.frameNumber = 0
        self.width = 32
        self.height = 32
        
        frameRange = 9
        row = 0
        self.addIdleFrameSet('./assets/warrior spritesheet calciumtrice.png', frameRange, row, self.width, self.height)
        row = 1
        self.addIdleFrameSet('./assets/warrior spritesheet calciumtrice.png', frameRange, row, self.width, self.height)
        row = 2
        self.addWalkFrameSet('./assets/warrior spritesheet calciumtrice.png', frameRange, row, self.width, self.height)
        row = 3
        self.addActionFrameSet('./assets/warrior spritesheet calciumtrice.png', frameRange, row, self.width, self.height)
        row = 4    
        self.addDeathFrameSet('./assets/warrior spritesheet calciumtrice.png', frameRange, row, self.width, self.height)
        
        
        
        # default sprite and image creation
        startFrame = self.idleFrameSet[self.frameNumber]
        self.updateFrame(startFrame)
        
    