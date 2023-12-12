"""This module contains the Melee class.

The Melee class is a subclass of the Entity class. It is used to create
melee units for both teams.

Author:
    Richard Roy

Date:
    2023-12-10

Resources:
    Player melee: https://opengameart.org/content/animated-warrior
    Enemy melee: https://opengameart.org/content/lpc-goblin
"""

from entity import Entity

class Melee(Entity):    # pylint: disable=too-many-instance-attributes
    """Class for creating melee units.
    
    The Melee class is a subclass of the Entity class. It is used to create
    melee units for both teams.
    """
    def __init__(self, start_location, team):    # pylint: disable=too-many-statements
        """Constructor for the Melee class.

        Args:
            start_location (tuple): The starting location of the melee unit. x, y coordinates.
            team (str): The team the melee unit belongs to. Can be 'player' or 'enemy'.
        """
        super().__init__(start_location, team)
        self.idle_frame_set = []
        self.walk_frame_set = []
        self.action_frame_set = []
        self.death_frame_set = []
        self.frame_number = 0

        # Base initializations and sprite sheet loading
        if team == 'player':
            self.width = 32
            self.height = 32
            self.attack_range = 64

            start_frame = 0
            end_frame = 10
            row = 0
            self.add_idle_frame_set(
                './assets/warrior spritesheet calciumtrice.png',
                start_frame, end_frame, row, self.width, self.height)
            row = 1
            self.add_idle_frame_set(
                './assets/warrior spritesheet calciumtrice.png',
                start_frame, end_frame, row, self.width, self.height)
            row = 2
            self.add_walk_frame_set(
                './assets/warrior spritesheet calciumtrice.png',
                start_frame, end_frame, row, self.width, self.height)
            row = 3
            self.add_action_frame_set(
                './assets/warrior spritesheet calciumtrice.png',
                start_frame, end_frame, row, self.width, self.height)
            row = 4
            self.add_death_frame_set(
                './assets/warrior spritesheet calciumtrice.png',
                start_frame, end_frame, row, self.width, self.height)
            
            # goblin sprite sheet does not have as many idle frames as warrior
            # so we will have to add the same frame multiple times to make it look
            # uniform
        elif team == 'enemy':
            self.width = 65
            self.height = 65
            self.attack_range = 65 + 32

            # frame group idle
            # start_frame = 5
            # end_frame = 7
            start_frame = 5
            end_frame = 6
            row = 1
            self.add_idle_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            self.add_idle_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            start_frame = 6
            end_frame = 7
            self.add_idle_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            self.add_idle_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            start_frame = 7
            end_frame = 8
            self.add_idle_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            self.add_idle_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            start_frame = 6
            end_frame = 7
            self.add_idle_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            self.add_idle_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)

            # frame group walk
            # start_frame = 0
            # end_frame = 5
            start_frame = 0
            end_frame = 1
            row = 1
            self.add_walk_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            self.add_walk_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            start_frame = 1
            end_frame = 2
            self.add_walk_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            self.add_walk_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            start_frame = 2
            end_frame = 3
            self.add_walk_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            self.add_walk_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            start_frame = 3
            end_frame = 4
            self.add_walk_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            self.add_walk_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            start_frame = 4
            end_frame = 5
            self.add_walk_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            self.add_walk_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            start_frame = 5
            end_frame = 6
            self.add_walk_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            self.add_walk_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)

            # frame group action
            # start_frame = 7
            # end_frame = 10
            start_frame = 7
            end_frame = 8
            row = 1
            self.add_action_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            self.add_action_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            start_frame = 8
            end_frame = 9
            self.add_action_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            self.add_action_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            start_frame = 9
            end_frame = 10
            self.add_action_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            self.add_action_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            start_frame = 10
            end_frame = 11
            self.add_action_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            self.add_action_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)

            # frame group death
            # start_frame = 0
            # end_frame = 4
            start_frame = 0
            end_frame = 1
            row = 4
            self.add_death_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            self.add_death_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            start_frame = 1
            end_frame = 2
            self.add_death_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            self.add_death_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            start_frame = 2
            end_frame = 3
            self.add_death_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            self.add_death_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            start_frame = 3
            end_frame = 4
            self.add_death_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            self.add_death_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            start_frame = 4
            end_frame = 5
            self.add_death_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)
            self.add_death_frame_set(
                './assets/goblinsword.png',
                start_frame, end_frame, row, self.width, self.height)

        start_frame = self.idle_frame_set[self.frame_number]
        self.update_frame(start_frame)
