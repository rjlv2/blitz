import pyautogui

COL_SIZE = 4;
ROW_SIZE = 4;

rows = [350, 430, 515, 595]
cols = [210, 295, 375, 460]

def get_coords(index):
	index = index - 1
	if (index < 16):
		return [cols[index%COL_SIZE], rows[index/COL_SIZE]]

def main():
	f = open("coords.txt", "r")
	f_lines = f.readlines()
	
	for line in f_lines:
		split_line = line.rstrip().split('-')
		int_line = map(int, split_line)
		pyautogui.moveTo(get_coords(int_line[0]))
		pyautogui.mouseDown()
		for pos in int_line:
			pyautogui.moveTo(get_coords(pos))
		pyautogui.mouseUp()
		print(int_line)
	
	#print(get_coords(15))
	#pyautogui.moveTo()

if __name__ == '__main__':
	main()
