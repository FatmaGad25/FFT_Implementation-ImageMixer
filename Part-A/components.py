## This is the abstract class that the students should implement
#from modesEnum import Modes
import numpy as np
import cv2

class image_components():

    def __init__(self, imgPath: str):
        """
        :param imgPath: absolute path of the image
        """
        self.imgPath = imgPath
        self.img = cv2.imread(self.imgPath, flags=cv2.IMREAD_GRAYSCALE).T
        self.imgShape = self.img.shape
        self.fft = np.fft.fft2(self.img)
        self.real = np.real(self.fft)
        self.imaginary = np.imag(self.fft)
        self.magnitude = np.abs(self.fft)
        self.phase = np.angle(self.fft)
        #self.uniformMagnitude = np.ones(self.img.shape)
        #self.uniformPhase = np.zeros(self.img.shape)

    def mix(self, imageToBeMixed: 'ImageModel', magnitudeOrRealRatio: float, phaesOrImaginaryRatio: float, mode: 'Modes'):
        """
        a function that takes ImageModel object mag ratio, phase ration and
        return the magnitude of ifft of the mix
        return type ---> 2D numpy array
        """
        w1 = magnitudeOrRealRatio
        w2 = phaesOrImaginaryRatio
        mixInverse = None

        if mode == Modes.magnitudeAndPhase:
            print("Mixing Magnitude and Phase")
            # mix1 = (w1 * M1 + (1 - w1) * M2) * exp((1-w2) * P1 + w2 * P2)
            M1 = self.magnitude
            M2 = imageToBeMixed.magnitude

            P1 = self.phase
            P2 = imageToBeMixed.phase

            magnitudeMix = w1*M1 + (1-w1)*M2
            phaseMix = (1-w2)*P1 + w2*P2

            combined = np.multiply(magnitudeMix, np.exp(1j * phaseMix))
            mixInverse = np.real(np.fft.ifft2(combined))

        elif mode == Modes.realAndImaginary:
            # mix2 = (w1 * R1 + (1 - w1) * R2) + j * ((1 - w2) * I1 + w2 * I2)
            print("Mixing Real and Imaginary")
            R1 = self.real
            R2 = imageToBeMixed.real

            I1 = self.imaginary
            I2 = imageToBeMixed.imaginary

            realMix = w1*R1 + (1-w1)*R2
            imaginaryMix = (1-w2)*I1 + w2*I2

            combined = realMix + imaginaryMix * 1j
            mixInverse = np.real(np.fft.ifft2(combined))

        return abs(mixInverse)
