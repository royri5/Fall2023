#google python style guide

#find way to avoid overlapping troops

# Unit
class Unit:
    def __init__():
        #hp
        #attack
        #unitType
        pass

    @property
    def hp(self):
        return self.__hp
    
    @hp.setter
    def hp(self, hp):
        if not hp:
            raise ValueError("Can't be None type for int.")