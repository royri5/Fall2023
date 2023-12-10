
import pygame as pg
from entity import Entity as Entity

class Melee(Entity):
    def __init__(self, startLocation, team):
        super().__init__(startLocation, team)
        self.idleFrameSet = []
        self.walkFrameSet = []
        self.actionFrameSet = []
        self.deathFrameSet = []
        self.frameNumber = 0
        
        if team == 'player':
            self.width = 32
            self.height = 32
            self.attackRange = 64
            
            startframe = 0
            endframe = 10
            row = 0
            self.addIdleFrameSet('./assets/warrior spritesheet calciumtrice.png', startframe, endframe, row, self.width, self.height)
            row = 1
            self.addIdleFrameSet('./assets/warrior spritesheet calciumtrice.png', startframe, endframe, row, self.width, self.height)
            row = 2
            self.addWalkFrameSet('./assets/warrior spritesheet calciumtrice.png', startframe, endframe, row, self.width, self.height)
            row = 3
            self.addActionFrameSet('./assets/warrior spritesheet calciumtrice.png', startframe, endframe, row, self.width, self.height)
            row = 4    
            self.addDeathFrameSet('./assets/warrior spritesheet calciumtrice.png', startframe, endframe, row, self.width, self.height)
        elif team == 'enemy':
            # print test
            self.width = 65
            self.height = 65
            self.attackRange = 130
            
            # goblin sprite sheet does not have as many idle frames as warrior
            # so we will have to add the same frame multiple times to make it look
            # uniform
            
            
            # frame group idle
            #startframe = 5
            #endframe = 7
            startframe = 5
            endframe = 6
            row = 1
            self.addIdleFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            self.addIdleFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            print('idle frames: ', self.idleFrameSet)
            startframe = 6
            endframe = 7
            self.addIdleFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            self.addIdleFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            startframe = 7
            endframe = 8
            self.addIdleFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            self.addIdleFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            startframe = 6
            endframe = 7
            self.addIdleFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            self.addIdleFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            
            # frame group walk
            # startframe = 0
            # endframe = 5
            startframe = 0
            endframe = 1
            row = 1
            self.addWalkFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            self.addWalkFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            startframe = 1
            endframe = 2
            self.addWalkFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            self.addWalkFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            startframe = 2
            endframe = 3
            self.addWalkFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            self.addWalkFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            startframe = 3
            endframe = 4
            self.addWalkFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            self.addWalkFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            startframe = 4
            endframe = 5
            self.addWalkFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            self.addWalkFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            startframe = 5
            endframe = 6
            self.addWalkFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            self.addWalkFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            
            
            # frame group action
            #startframe = 7
            #endframe = 10
            startframe = 7
            endframe = 8
            row = 1
            self.addActionFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            self.addActionFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            startframe = 8
            endframe = 9
            self.addActionFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            self.addActionFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            startframe = 9
            endframe = 10
            self.addActionFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            self.addActionFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            startframe = 10
            endframe = 11
            self.addActionFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            self.addActionFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            
            # frame group death
            #startframe = 0
            #endframe = 4
            startframe = 0
            endframe = 1
            row = 4
            self.addDeathFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            self.addDeathFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            startframe = 1
            endframe = 2
            self.addDeathFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            self.addDeathFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            startframe = 2
            endframe = 3
            self.addDeathFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            self.addDeathFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            startframe = 3
            endframe = 4
            self.addDeathFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            self.addDeathFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            startframe = 4
            endframe = 5
            self.addDeathFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            self.addDeathFrameSet('./assets/goblinsword.png', startframe, endframe, row, self.width, self.height)
            
                 
        
        
        # default sprite and image creation
        # print out the frame sets
        print('idle frames: ', self.idleFrameSet)
        
        startFrame = self.idleFrameSet[self.frameNumber]
        self.updateFrame(startFrame)
        
    