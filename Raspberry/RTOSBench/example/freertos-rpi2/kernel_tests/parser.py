import re
from statistics import mean
from sys import argv
import pandas as pd
import numpy
import matplotlib.pyplot as plt
#import matplotlib
#matplotlib.use('Agg')

# name of the output file
filepath = argv[1]

# text the matches timers in output
t1 = "t1"
t2 = "t2"

# we will store all the values
timer_t1 = []
timer_t2 = []

f = open("stats.csv", "w")
f.write("Max,Min,Average,Median\n")

stats_array = {}

def Diff(li1, li2):
    return (list(set(li2) - set(li1)))

def make_stats(timer_t1, timer_t2, max_ref, min_ref,type):
    t1 = numpy.abs(numpy.array(timer_t1))
    t2 = numpy.abs(numpy.array(timer_t2))
    #print(t1)
    #print(t2)
    diff = numpy.abs(t2 - t1)
    avg = numpy.mean(diff)
    if not type in stats_array.keys():
        stats_array[type] = []
    stats_array[type].append({ 'min': min_ref, 'max':max_ref,'avg':avg, 'median': numpy.median(diff)})
    f.write( str(max_ref) +"," + str(min_ref) + "," + str(avg) + ","+ str(numpy.median(diff)) + "\n")

array_index = '';
with open(filepath,errors='ignore') as fp:
    for line in fp:
        #print(line)
        if (line.find("-- ") != -1):
           match = re.search(r'-- (.*) --', line)
           #print(match.group(1))
           array_index =match.group(1)

        if (line.find("max") != -1):
            # end of stats, we need new stats
            max_match = re.search(r'max=(\d*)', line)
            min_line = fp.readline()
            min_match = re.search(r'min=(\d*)', min_line)
            make_stats(timer_t1,timer_t2,int(max_match.group(1)),int(min_match.group(1)),array_index)
            # deleting counter for another run
            timer_t1 = []
            timer_t2 = []
        # find t1 or t2
        if (line.find(t1) != -1):
            match = re.search(r't1 (-?\d*)', line)
            timer_t1.append( int(match.group(1))) # matching the number
        else:
            if (line.find(t2) != -1):
                match = re.search(r't2 (-?\d*)', line)
                timer_t2.append(int(match.group(1)))  # matching the number

f.close()
def ploting(name):
    df = pd.read_csv(name + ".csv")
    df.plot.bar()
    plt.title(name)
    #plt.show()
    plt.savefig(name)

df = pd.read_csv('stats.csv')
df.plot.bar()
#plt.show()
plt.savefig(filepath)

for name, strings in stats_array.items():
    pom = name
    name = name.replace(" ", "_")
    name =name.replace(":", "")
    name = name.lower()
    l = open(name + ".csv", "w")
    l_max = open(name + "_max.csv", "w")
    l_without_max = open(name + "_nomax.csv", "w")
    #l.write(name + "\n")
    l.write("Max,Min,Average,Median\n")
    l_without_max.write("Min,Average,Median\n")
    l_max.write("Max\n")
    for string_dic in strings:
        l.write(str(string_dic["max"]) +"," + str(string_dic["min"]) + "," + str(string_dic["avg"]) + ","+ str(string_dic["median"])  + "\n")
        l_max.write(str(string_dic["max"]))
        l_without_max.write( str(string_dic["min"]) + "," + str(string_dic["avg"]) + ","+ str(string_dic["median"])  + "\n")
    l.close()
    l_max.close()
    l_without_max.close()
    ploting(name)
    ploting(name)
    ploting(name+"_max")
    ploting(name + "_nomax")
