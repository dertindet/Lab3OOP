from menu import Menu
import unittest
from test_cases import TestInstrumentalWork, TestMusicCollection, TestSong
class main:
    def __init__(self):
        self.menu = Menu()

    def run(self):
        self.menu.show_main_menu()  



if __name__ == "__main__":
    unittest.main()
    app = main()
    app.run()
