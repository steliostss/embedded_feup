import pandas as pd
import numpy as np
from matplotlib import pyplot as plt
from brokenaxes import brokenaxes
from sys import argv
import csv

tests = {
    "mq"                : {"mq_receive_block", "mq_signal_unblock"},
    "mq_processing"     : {"mq_receive", "mq_send"},
    "mq_workload"       : {"mq_workload"},
    "mutex"             : {"mutex_release_unblock", "mutex_request_block"},
    "mutex_pip"         : {"mutex_pip"},
    "mutex_processing"  : {"mutex_acquisition", "mutex_release"},
    "mutex_workload"    : {"mutex_workload"},
    "round_robin"       : {"cooperating_scheduling_ctx_switch"},
    "sem"               : {"sem_signal_unblock", "sem_wait_block"},
    "sem_prio"          : {"sem_singaling_with_prio"},
    "sem_processing"    : {"sem_signal", "sem_wait"}
    # ,"sem_workload"     : {}
}

columns = [ "Max", "Min", "Average", "Median" ]
line = "Max, Min, Average, Median"

addition  = ""
extension = ".csv"
plotspath = "png/"
csvpath   = "csv/"

def write_to_file(data, file):
    for counter in range(0,len(data)):
        if counter != len(data)-1:
            file.write(data[counter] + ", ")
        else:
            file.write(data[counter])

def line_prepender(filename, line):
    with open(filename, 'r+') as f:
        content = f.read()
        f.seek(0, 0)
        f.write(line.rstrip('\r\n') + '\n' + content)

def calc_median(file, test):
    filename = test+'/'+csvpath+file
    calc_medians = list()
    df = pd.read_csv(filename+extension)
    with open(filename+"_averaged"+extension, 'w') as f:
        for column in columns:
            col_to_calculate = df[column]
            calc_medians.append(np.median(col_to_calculate))
        # print("test: ", test)
        # print("file: ", file)
        # print("strip: ", file.strip(test+'_'))
        # print("--------------------------------------")
        wb = csv.writer(f)
        calc_medians.insert(0, file.strip(test+'_'))
        wb.writerow(calc_medians)


for i in tests:
    for file in tests[i]:
        # filename = i+'/'+addition+csvpath+file
        # filename = i+addition+csvpath+file+"_averaged"+extension
        calc_median(file, i)

