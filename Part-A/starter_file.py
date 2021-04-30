from PyQt5 import QtWidgets
from mixer import Ui_MainWindow
import sys


class ApplicationWindow(QtWidgets.QMainWindow):
    def __init__(self):
        super(ApplicationWindow, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.images=[self.ui.output1,self.ui.output2,self.ui.img1,self.ui.img1_component,self.ui.img2,self.ui.img2_component]
        for i in range(len(self.images)):
            self.images[i].ui.histogram.hide()
            self.images[i].ui.roiBtn.hide()
            self.images[i].ui.menuBtn.hide()
            self.images[i].ui.roiPlot.hide()



def main():
    app = QtWidgets.QApplication(sys.argv)
    application = ApplicationWindow()
    application.show()
    app.exec_()


if __name__ == "__main__":
    main()