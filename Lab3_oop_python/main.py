from menu import Menu

class main:
    def __init__(self):
        self.menu = Menu()

    def run(self):
        self.menu.show_main_menu()  



if __name__ == "__main__":
    app = main()
    app.run()
