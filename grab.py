from PIL import ImageOps
import numpy as np
import pyscreenshot as ImageGrab
import os
import time
 
def screenGrab():
    box = (154, 285, 513, 642)
    im = ImageGrab.grab(box)
    #im.save(os.path.dirname(os.path.realpath(__file__)) + '/full_snap_' + str(int(time.time())) + '.png', 'PNG')
    return im

def get_box_one():
    box = (199,333,222,361)
    im = ImageGrab.grab(box)
    im = ImageOps.grayscale(ImageGrab.grab(box))
    #im_inv = ImageOps.invert(im)
    im_arr = np.array(im)
    im_filtered = np.where(im_arr < 128, 1, 0)
    a = np.sum(im_filtered)
    print np.array(im_filtered)
    print "1 " + str(a)
    im.save(os.getcwd() + '/images/1' + '.png', 'PNG')    
    return a

def get_box_two():
    box = (281,333,304,361)
    im = ImageOps.grayscale(ImageGrab.grab(box))
    #a = np.sum(im.getcolors())
    im_arr = np.array(im)
    im_filtered = np.where(im_arr < 128, 1, 0)
    a = np.sum(im_filtered)
    print np.array(im_filtered)
    print "2 " + str(a)
    im.save(os.getcwd() + '/images/2' + '.png', 'PNG')    
    return a

def get_box_three():
    box = (363,333,386,361)
    im = ImageOps.grayscale(ImageGrab.grab(box))
    #a = np.sum(im.getcolors())
    im_arr = np.array(im)
    im_filtered = np.where(im_arr < 128, 1, 0)
    a = np.sum(im_filtered)
    print np.array(im_filtered)
    print "3 " + str(a)
    im.save(os.getcwd() + '/images/3' + '.png', 'PNG')    
    return a

def get_box_four():
    box = (445,333,468,361)
    im = ImageOps.grayscale(ImageGrab.grab(box))
    #a = np.sum(im.getcolors())
    im_arr = np.array(im)
    im_filtered = np.where(im_arr < 128, 1, 0)
    a = np.sum(im_filtered)
    print np.array(im_filtered)
    print "4 " + str(a)
    im.save(os.getcwd() + '/images/4' + '.png', 'PNG')    
    return a

def get_box_five():
    box = (199,416,222,444)
    im = ImageOps.grayscale(ImageGrab.grab(box))
    #a = np.sum(im.getcolors())
    im_arr = np.array(im)
    im_filtered = np.where(im_arr < 128, 1, 0)
    a = np.sum(im_filtered)
    print np.array(im_filtered)
    print "5 " + str(a)
    im.save(os.getcwd() + '/images/5' + '.png', 'PNG')    
    return a

def get_box_six():
    box = (281,416,304,444)
    im = ImageOps.grayscale(ImageGrab.grab(box))
    #a = np.sum(im.getcolors())
    im_arr = np.array(im)
    im_filtered = np.where(im_arr < 128, 1, 0)
    a = np.sum(im_filtered)
    print np.array(im_filtered)
    print "6 " + str(a)
    im.save(os.getcwd() + '/images/6' + '.png', 'PNG')    
    return a

def get_box_seven():
    box = (363,416,386,444)
    im = ImageOps.grayscale(ImageGrab.grab(box))
    #a = np.sum(im.getcolors())
    im_arr = np.array(im)
    im_filtered = np.where(im_arr < 128, 1, 0)
    a = np.sum(im_filtered)
    print np.array(im_filtered)
    print "7 " + str(a)
    im.save(os.getcwd() + '/images/7' + '.png', 'PNG')    
    return a

def get_box_eight():
    box = (445,416,468,444)
    im = ImageOps.grayscale(ImageGrab.grab(box))
    #a = np.sum(im.getcolors())
    im_arr = np.array(im)
    im_filtered = np.where(im_arr < 128, 1, 0)
    a = np.sum(im_filtered)
    print np.array(im_filtered)
    print "8 " + str(a)
    im.save(os.getcwd() + '/images/8' + '.png', 'PNG')    
    return a

def get_box_nine():
    box = (199,499,222,527)
    im = ImageOps.grayscale(ImageGrab.grab(box))
    #a = np.sum(im.getcolors())
    im_arr = np.array(im)
    im_filtered = np.where(im_arr < 128, 1, 0)
    a = np.sum(im_filtered)
    print np.array(im_filtered)
    print "9 " + str(a)
    im.save(os.getcwd() + '/images/9' + '.png', 'PNG')    
    return a

def get_box_ten():
    box = (281,499,304,527)
    im = ImageOps.grayscale(ImageGrab.grab(box))
    #a = np.sum(im.getcolors())
    im_arr = np.array(im)
    im_filtered = np.where(im_arr < 128, 1, 0)
    a = np.sum(im_filtered)
    print np.array(im_filtered)
    print "10 " + str(a)
    im.save(os.getcwd() + '/images/10' + '.png', 'PNG')    
    return a

def get_box_eleven():
    box = (363,499,386,527)
    im = ImageOps.grayscale(ImageGrab.grab(box))
    #a = np.sum(im.getcolors())
    im_arr = np.array(im)
    im_filtered = np.where(im_arr < 128, 1, 0)
    a = np.sum(im_filtered)
    print np.array(im_filtered)
    print "11 " + str(a)
    im.save(os.getcwd() + '/images/11' + '.png', 'PNG')    
    return a

def get_box_twelve():
    box = (445,499,468,527)
    im = ImageOps.grayscale(ImageGrab.grab(box))
    #a = np.sum(im.getcolors())
    im_arr = np.array(im)
    im_filtered = np.where(im_arr < 128, 1, 0)
    a = np.sum(im_filtered)
    print np.array(im_filtered)
    print "12 " + str(a)
    im.save(os.getcwd() + '/images/12' + '.png', 'PNG')    
    return a

def get_box_thirteen():
    box = (199,582,222,610)
    im = ImageOps.grayscale(ImageGrab.grab(box))
    #a = np.sum(im.getcolors())
    im_arr = np.array(im)
    im_filtered = np.where(im_arr < 128, 1, 0)
    a = np.sum(im_filtered)
    print np.array(im_filtered)
    print "13 " + str(a)
    im.save(os.getcwd() + '/images/13' + '.png', 'PNG')    
    return a

def get_box_fourteen():
    box = (281,582,304,610)
    im = ImageOps.grayscale(ImageGrab.grab(box))
    #a = np.sum(im.getcolors())
    im_arr = np.array(im)
    im_filtered = np.where(im_arr < 128, 1, 0)
    a = np.sum(im_filtered)
    print np.array(im_filtered)
    print "14 " + str(a)
    im.save(os.getcwd() + '/images/14' + '.png', 'PNG')    
    return a

def get_box_fifteen():
    box = (363,582,386,610)
    im = ImageOps.grayscale(ImageGrab.grab(box))
    #a = np.sum(im.getcolors())
    im_arr = np.array(im)
    im_filtered = np.where(im_arr < 128, 1, 0)
    a = np.sum(im_filtered)
    print np.array(im_filtered)
    print "15 " + str(a)
    im.save(os.getcwd() + '/images/15' + '.png', 'PNG')    
    return a

def get_box_sixteen():
    box = (445,582,468,610)
    im = ImageOps.grayscale(ImageGrab.grab(box))
    #a = np.sum(im.getcolors())
    im_arr = np.array(im)
    im_filtered = np.where(im_arr < 128, 1, 0)
    a = np.sum(im_filtered)
    print np.array(im_filtered)
    print "16 " + str(a)
    im.save(os.getcwd() + '/images/16' + '.png', 'PNG')    
    return a


def main():
    #screenGrab()
    get_box_one()
    get_box_two()
    get_box_three()
    get_box_four()
    get_box_five()
    get_box_six()
    get_box_seven()
    get_box_eight()
    get_box_nine()
    get_box_ten()
    get_box_eleven()
    get_box_twelve()
    get_box_thirteen()
    get_box_fourteen()
    get_box_fifteen()
    get_box_sixteen()
    
 
if __name__ == '__main__':
    main()
