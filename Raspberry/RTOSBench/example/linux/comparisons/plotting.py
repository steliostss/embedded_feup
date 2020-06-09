import pandas as pd
import numpy as np
from matplotlib import pyplot as plt
from brokenaxes import brokenaxes
from sys import argv
import csv


tests = [
    'context_switch'
    # ,'sem_comparisons'
    # ,'mq_comparisons'
    # ,'mutex_comparisons'
]

bar_labels = ['Max', 'Min', 'Average', 'Median' ]
x_labels = "Name"

# context_switch
# usecols=[1,2,3,4]

for test in tests:
    with open(test+'.csv', newline='') as csvfile:
        df = pd.read_csv(csvfile, names=bar_labels)
    fig = plt.figure(figsize=(5,5))
    # bax = brokenaxes(ylims=((0, 0.75), (1.5, 1.7)), hspace=0.1)
    bax = brokenaxes(xlims=((0, 0.75), (1.5, 1.7)), hspace=0.1)
    bax.barh(range(0, len(df)), df['Max'], height=0.3)
    # bax.barh(range(0, len(df)+3), df['Min'], height=0.3)
    # bax.barh(range(0, len(df)), df['Average'], height=0.3)
    # bax.barh(range(0, len(df)), df['Median'], height=0.3)
    bax.legend(loc=4)
    bax.set_xlabel('time')
    bax.set_ylabel('value')
    plt.show()
    # ax = data.plot.bar(rot=0)
    # plt.savefig(test+'test'+'.png')

# np.arrange(0, len(df)), 