## This is the abstract class that the students should implement
#from modesEnum import Modes
import numpy as np
import cv2

# class image_components():
class inputimg():

    def __init__(self, imgPath: str):
        """
        :param imgPath: absolute path of the image
        """
        self.imgPath = imgPath
        self.img = cv2.imread(self.imgPath,flags=cv2.IMREAD_GRAYSCALE)
        self.imgShape = self.img.shape
        self.fft = np.fft.fft2(self.img)
        self.real = np.real(self.fft)
        self.imaginary = np.imag(self.fft)
        self.phase = np.angle(self.fft)
        self.amplitude = np.abs(self.fft)

        self.fftshift = np.fft.fftshift(self.fft)    
        self.magnitude = 20*np.log(np.abs(np.fft.fftshift(self.fft)))
        self.realshift = 20*np.log(np.real(np.fft.fftshift(self.fft)))      
        self.phaseshift = np.angle(np.fft.fftshift(self.fft))
        self.imaginaryshift = np.imag(np.fft.fftshift(self.fft))
        
    # def mix(self, imageToBeMixed: 'ImageModel', magnitudeOrRealRatio: float, phaesOrImaginaryRatio: float, mode: 'Modes', type1):
    def mix(self, imageToBeMixed: 'inputimg', gain1: float, gain2: float, mode: str, type1: str):
        """
        a function that takes ImageModel object mag ratio, phase ration and
        return the magnitude of ifft of the mix
        return type ---> 2D numpy array
        """
        # gain1 = magnitudeOrRealRatio
        # gain2 = phaesOrImaginaryRatio

        gain1=gain1 / 100.0
        gain2=gain2 / 100.0
        mode= mode
        type1=type1
        mixInverse = None

        if mode == "magphase":
            print("Mixing Magnitude and Phase")
            # mix1 = (gain1 * M1 + (1 - gain1) * M2) * exp((1-gain2) * P1 + gain2 * P2)

            M1 = self.amplitude
            M2 = imageToBeMixed.amplitude

            P1 = self.phase
            P2 = imageToBeMixed.phase
            if (type1 == "Magnitude"):

                magnitudeMix = gain1*M1 + (1-gain1)*M2
                phaseMix = (1-gain2)*P1 + gain2*P2

            elif (type1 == "Phase"):
                phaseMix = gain1*P1 + (1-gain1)*P2
                magnitudeMix = gain2*M2 + (1-gain2)*M1

            combined = np.multiply(magnitudeMix, np.exp(1j * phaseMix))
            mixInverse = np.real(np.fft.ifft2(combined))


        elif mode == "realimg":
            # mix2 = (gain1 * R1 + (1 - gain1) * R2) + j * ((1 - gain2) * I1 + gain2 * I2)
            print("Mixing Real and Imaginary")
            R1 = self.real
            R2 = imageToBeMixed.real

            I1 = self.imaginary
            I2 = imageToBeMixed.imaginary

            if (type1 == "Real"):
                realMix = gain1*R1 + (1-gain1)*R2
                imaginaryMix = (1-gain2)*I1 + gain2*I2

            elif (type1== "Imaginary"):
                imaginaryMix= gain1*I1 + (1-gain1)*P2 
                realMix = gain2*R2 + (1-gain2)*R1

            combined = realMix + imaginaryMix * 1j
            mixInverse = np.real(np.fft.ifft2(combined))

        return abs(mixInverse)
