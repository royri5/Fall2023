# ADAPTED FROM: https://www.youtube.com/watch?v=M6e3_8LHc7A
import pygame as pg

class Spritesheet():
    def __init__(self, image):
        self.sheet = image
    
    def get_image(self, frame, row, width, height, color):
        image = pg.Surface((width, height)).convert_alpha()
        # row 0 is the first row
        image.blit(self.sheet, (0, 0), ((frame * width), (row * height), width, height))
        
        image.set_colorkey(color)
        return image 