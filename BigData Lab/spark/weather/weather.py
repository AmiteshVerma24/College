# Import modules
import sys
from pyspark import SparkContext
# Check input from terminal
if(len(sys.argv)!=4):
    print("Provide Input File and Output Directory")
    sys.exit(0)
# Create spark context
sc = SparkContext()
# Read the input file
f = sc.textFile(sys.argv[1])
# 
temp=f.map(lambda x: (int(x[15:19]),int(x[87:92])))
# 
mini=temp.reduceByKey(lambda a,b:a if a<b else b)
maxi=temp.reduceByKey(lambda a,b:a if a>b else b)
# 
mini.saveAsTextFile(sys.argv[2])
maxi.saveAsTextFile(sys.argv[3])

