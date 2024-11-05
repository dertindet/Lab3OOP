class Composition:
    def __init__(self, title: str, duration: int):
        self.title = title
        self.duration = duration

    def get_title(self) -> str:
        return self.title

    def get_duration(self) -> int:
        return self.duration
    def show(self):
        return((f"Title: {self.title}, Duration: {self.duration} sec"))

