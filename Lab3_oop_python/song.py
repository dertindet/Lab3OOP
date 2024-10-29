from composition import Composition

class Song(Composition):
    def __init__(self, title: str, duration: int, vocalist: str):
        super().__init__(title, duration)
        self.vocalist = vocalist

    def get_vocalist(self) -> str:
        return self.vocalist
