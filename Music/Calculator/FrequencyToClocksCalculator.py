import math
def frequencyToPeriod(frequency):
    return 1.0/float(frequency)*1000000

def timeToClockCycles(time, clockFrequency):
    return time/frequencyToPeriod(clockFrequency)

XTAL_FREQ =  input("Input the Crystal Frequency in Hertz: ")

frequency = input("Input Sound Frequency in Hertz: ")
validPrescaler = False
while (not validPrescaler):
    try:
        prescalerRatio = input("Input Prescaler ratio: ")
        ratio = int(prescalerRatio.split(":")[1])
        validPrescaler = True
    except:
        print("This is not a valid Prescaler. Input it in the 1:x format")



period = frequencyToPeriod(frequency)
clocks = timeToClockCycles(period, XTAL_FREQ)
print("Number of Clock Cycles for half a period: ", int(clocks)/ratio/2)