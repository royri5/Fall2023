"""This module contains the Spritesheet class.

Used to extract sprites from a spritesheet.

Author:
    Richard Roy

Date:
    2023-12-10

Resources:
    https://www.youtube.com/watch?v=M6e3_8LHc7A
"""
import pygame as pg

class Spritesheet():
    """Class used to grab sprites from a spritesheet.

    Attributes:
        sheet (Surface): The spritesheet as a pygame surface.
    """

    def __init__(self, image):
        self.sheet = image

    def get_image(self, frame, row, width, height):
        """Extracts an image from the spritesheet.

        Args:
            frame (int): What frame from row.
            row (int): What row from sheet.
            width (int): Sprite width.
            height (int): Sprite height.

        Returns:
            Surface: The sprite as a pygame surface.
        """
        image = pg.Surface((width, height)).convert_alpha()
        image.blit(self.sheet, (0, 0), ((frame * width), (row * height), width, height))
        image.set_colorkey((0, 0, 0))
        return image

    @property
    def sheet(self):
        return self.__sheet

    @sheet.setter
    def sheet(self, value):
        if not value:
            raise ValueError("Spritesheet cannot be None.")
        if not isinstance(value, pg.Surface):
            raise TypeError("Spritesheet must be a pygame Surface.")
        self.__sheet = value
