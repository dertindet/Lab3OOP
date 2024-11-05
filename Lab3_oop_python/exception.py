class MusicCollectionException(Exception):
    pass


class MyIndexOutOfBoundsException(MusicCollectionException):
    def __str__(self):
        return "Error: Index out of bounds"

class MyInvalidChoiceException(MusicCollectionException):
    def __str__(self):
        return "Error: Invalid number."
    