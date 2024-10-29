from composition import Composition

class InstrumentalWork(Composition):
    def __init__(self, title: str, duration: int, composer: str):
        super().__init__(title, duration)
        self.composer = composer

    def get_composer(self) -> str:
        return self.composer
