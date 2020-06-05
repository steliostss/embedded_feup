import csv
import numpy
import matplotlib.pyplot as plt

filepath = "allstats.csv"
filepath2 = "allstats_linux.csv"

f = open("comparison.csv", "w")
labels = { "mq": ['mq','mq_processing','mq_workload' ], "mutex":['mutex','mutex_pip','mutex_workload','mutex_processing' ],
         "sem": ["sem", 'sem_processing','sem_prio'], "round_robin": ["round_robin"]}

min_index = 1;

def plot_bar(linux_means, rasp_means, labels, name):
    #print(labels)
    #print(linux_means)
    #print(rasp_means)
    x = numpy.arange(len(labels))  # the label locations
    width = 0.35  # the width of the bars

    fig, ax = plt.subplots()
    rects1 = ax.bar(x - width / 2, linux_means, width, label='Linux')
    rects2 = ax.bar(x + width / 2, rasp_means, width, label='Raspberry')

    # Add some text for labels, title and custom x-axis tick labels, etc.
    ax.set_ylabel('Median')
    ax.set_title(name)
    ax.set_xticks(x)
    ax.set_xticklabels(labels)
    ax.legend()

    def autolabel(rects):
        """Attach a text label above each bar in *rects*, displaying its height."""
        for rect in rects:
            height = rect.get_height()
            ax.annotate('{}'.format(height),
                        xy=(rect.get_x() + rect.get_width() / 2, height),
                        xytext=(0, 3),  # 3 points vertical offset
                        textcoords="offset points",
                        ha='center', va='bottom')

    autolabel(rects1)
    autolabel(rects2)
    fig.tight_layout()
    plt.savefig(name)
   # plt.show()


def getArray(filepath3, median):
    first = True
    name = 'def'
    median_array = {}
 #   print("neeeew\n")
    #print(filepath)
    with open(filepath3, newline='') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=',')
        for row in spamreader:
            pom = row[0]
          #  print(row)
            if pom.find("Max") != -1:
                #print("ffff")
                continue
            else:
                if first:
                    #print("name is: " + row[0])
                    name = row[0]
                    first = False
                    median_array[name] = []
                    #spamreader.
                else:
                    if (row[0].find("--------") != -1):
                        first = True
                    else:
                        #print(name)
                        #value = int(flow(row[median]))
                        value = int(float(row[median]))
                        if (value > 10000):
                            value = int(float(row[min_index]))
                            print("taking mic instead of max: " + name )
                        median_array[name].append(value)
    return median_array

median_array_rasb = getArray(filepath, 3)
median_array_linux = getArray(filepath2, 3)

#print(median_array_rasb)
#print(median_array_linux)
for x, y in median_array_rasb.items():
    med_array = numpy.array(y)
    new_value = round(numpy.mean(med_array),2)
    median_array_rasb[x] = new_value

for x, y in median_array_linux.items():
    med_array = numpy.array(y)
    
    new_value = round(numpy.mean(med_array),2)
    if (new_value > 10000):
        new_value = numpy.min(med_array)
    median_array_linux[x] = new_value

linux = []
rasp = []
#print(median_array_rasb)
#print(median_array_linux)
for x,label in labels.items():
    linux = []
    rasp = []
    for item in label:
        linux.append(median_array_linux[item])
        rasp.append(median_array_rasb[item])
    plot_bar(linux, rasp,label,x)
