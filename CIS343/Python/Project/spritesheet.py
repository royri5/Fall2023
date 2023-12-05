# ADAPTED FROM: https://www.youtube.com/watch?v=M6e3_8LHc7A
import pygame as pg

class Spritesheet():
    def __init__(self, image):
        self.sheet = image
    
    def get_image(self, frame, row, width, height, color):
        image = pg.Surface((width, height)).convert_alpha()
        #image.blit(self.sheet, (0, 0), ((frame * width), 0, width, height))
        # row 0 is the first row
        image.blit(self.sheet, (0, 0), ((frame * width), (row * height), width, height))
        
        
        
        
        #image.blit(self.sheet, (0, row * height), area)
        #image = pg.transform.scale(image, (width * scale, height * scale))
        image.set_colorkey(color)
        return image 