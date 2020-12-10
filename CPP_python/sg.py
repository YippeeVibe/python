import csv
import time
def readcsv(a):
    a=a.decode('utf-8')
    arr = []
    print(a)
    with open(a) as csv_file:
        print("do")
        csv_reader = csv.reader(csv_file, delimiter=',')
        line_count = 0
        for row in csv_reader:
            if line_count == 0:
                pass
            else:
                dealTime = float(time.mktime(time.strptime(row[0],"%Y-%m-%d")))
                arr.append([dealTime,float(row[3]),float(row[4]),float(row[5]),float(row[6])])
            line_count += 1
    return arr
