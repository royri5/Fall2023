# REFERENCED: https://www.geeksforgeeks.org/mmouse-clicks-on-sprites-in-pygame/

import os
import pygame as pg
import math
from spritesheet import Spritesheet as Spritesheet

class Entity(pg.sprite.Sprite):
    def __init__(self, startLocation):
        super(Entity, self).__init__()
        
        sprite_sheet_image = pg.image.load('./assets/warrior spritesheet calciumtrice.png').convert_alpha()
        self.sprite_sheet = Spritesheet(sprite_sheet_image)
        startFrame = self.sprite_sheet.get_image(0, 32, 32, (0, 0, 0))
        self.location = startLocation
        self.destination = startLocation
        self.isMoving = False
        self.direction = 1
        self.updateFrame(startFrame)
        #self.callback = callback
        self.selected = False
        self.team = 'player'
        self.speed = 100
    
    # when calling, update location
    def updateFrame(self, frame):
        self.image = frame
        self.rect = self.image.get_rect()
        self.rect.centerx = self.location[0]
        self.rect.centery = self.location[1]
        #self.direction = 
        if self.isMoving == False:
            self.destination = self.location
        
    def draw(self, screen):
        #frame_0 = self.getImage(self.image, 32, 32)
        screen.blit(self.image, self.rect)
        #screen.blit(frame_0, self.rect)

    # head towards location until you reach it
    # or until you run into the game border
    def moveTo(self, x, y):
        self.isMoving = True
        self.destination = (x, y)
        
    # "AI" movement
    # make sure it works for all 4 directions (might need abs())
    def update(self, delta):
        # update location
        self.location = (self.rect.centerx, self.rect.centery)
        if self.destination != self.location:
            xDiff = self.destination[0] - self.location[0]
            yDiff = self.destination[1] - self.location[1]
            distance = math.sqrt(xDiff**2 + yDiff**2)
            if distance > 0:
                directionX = xDiff / distance
                directionY = yDiff / distance
                
                self.rect.centerx += directionX * self.speed * delta
                self.rect.centery += directionY * self.speed * delta
            #if abs(self.rect.centerx - self.destination[0]) < 5 and abs(self.rect.centery - self.destination[1]) < 5:
                
            
        else:
            self.isMoving = False
            
        # self.rect.y += 100 * delta * self.direction
        # if self.rect.y > self.startLocation[1] + 100 or self.rect.y < self.startLocation[1] - 100:
        #     self.direction *= -1
        # for event in events:
        #     if event.type == pg.MOUSEBUTTONUP:
        #         if self.rect.collidepoint(event.pos):
        #             self.callback()
        pass
