from PyQt5 import QtWidgets
from PyQt5 import QtCore, QtGui, QtWidgets
from mixer import Ui_MainWindow
import sys
import cv2
import numpy as np
#import logging
# counter=-1

class ApplicationWindow(QtWidgets.QMainWindow):
    def __init__(self):
        super(ApplicationWindow, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.images=[self.ui.img1,self.ui.img2,self.ui.img1_component,self.ui.img2_component,self.ui.output1,self.ui.output2]
        # self.images=[self.ui.img2,self.ui.img1_component,self.ui.img2_component,self.ui.output1,self.ui.output2]

        for i in range(len(self.images)):
            self.images[i].ui.histogram.hide()
            self.images[i].ui.roiBtn.hide()
            self.images[i].ui.menuBtn.hide()
            self.images[i].ui.roiPlot.hide()
        self.counter=-1
        self.ui.pause.clicked.connect(lambda:self.opensignal())
        self.ui.actionOpen.triggered.connect(lambda:self.Components())

    

    # def readsignal(self):
    #     self.ui.fname=QtGui.QFileDialog.getOpenFileName(self,' txt or CSV or xls',"QFileDialog.getOpenFileName()", "","All Files (*);;Python Files (*.py)")
    #     self.ui.path=self.ui.fname[0]
    #     self.ui.img= cv2.imread(self.ui.path)
    #     print (self.ui.img)

    # def opensignal(self):
    #     self.ui.readsignal()
    #     #self.ui.images[self.counter%3].plotItem.getViewBox().setLimits(xMin=0,xMax=len(self.data[self.counter]))
        # self.ui.counter+=1
    #     self.ui.img1.setImage(self.img.T)
    #     # self.ui.img1.adjustSize()
    #     # self.ui.img1.setPixmap(QtGui.QPixmap(self.path))

    def readsignal(self):
        #self.fname=QtGui.QFileDialog.getOpenFileName(self,"txt or CSV or xls","QFileDialog.getOpenFileName()", "","All Files (*);;Python Files (*.py)")
        self.fname=QtGui.QFileDialog.getOpenFileName(self, 'Open file', "Image files (*.jpg *.gif)")
        self.path=self.fname[0]
        self.img= cv2.imread(self.path,0)
        print (self.img)
    def opensignal(self):
        self.readsignal()
        self.counter+=1
        self.ui.images[self.counter%2].setImage(self.img.T)
        # self.img1.setImage(self.img.T)

    def Components(self):
        self.fft = np.fft.fft2(self.img)
        # print(self.fft)
        self.amplitude = abs(self.fft)
        self.magnitude = 20*np.log(np.abs(np.fft.fftshift(self.fft)))
        # self.fshift = np.fft.fftshift(self.fft)
        # self.ishift = np.fft.ifftshift(fshift)
        self.phase = np.angle(self.fft)
        self.real = np.real(self.fft)
        self.imaginary = np.imag(self.fft)
        self.imagnitude= np.fft.ifft2(self.magnitude)
        self.iamplitude= np.fft.ifft2(self.amplitude)
        print(self.phase)
        self.ui.images[2+self.counter%2].setImage(self.magnitude.T)



if __name__ == "__main__":

    app = QtWidgets.QApplication(sys.argv)
    application = ApplicationWindow()
    application.show()
    app.exec_()
