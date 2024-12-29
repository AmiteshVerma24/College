import random
from pyspark.sql import SparkSession
from pyspark.sql.functions import col, avg, when, rand
# Initialize Spark session
spark = SparkSession.builder \
 .appName("/content/Airlines.csv") \
 .getOrCreate()
# Load the data
file_path = "/content/Airlines.csv" # Replace with your file path
data = spark.read.csv(file_path, header=True, inferSchema=True)
# Add a random delay time column
# Assign random values (1-30) to rows where Delay = 1, and 0 for Delay= 0
data_with_delay_time = data.withColumn(
 "DelayTime",
 when(col("Delay") == 1, (rand() * 30).cast("int") + 1).otherwise(0)
)
# Display data with the new DelayTime column
print("Data with added DelayTime column:")
data_with_delay_time.show()
# Filter flights delayed by more than 15 minutes (using DelayTime)
delayed_flights = data_with_delay_time.filter(col("DelayTime") > 15)
print("Flights delayed by more than 15 minutes:")
delayed_flights.show()
# Stop Spark session
spark.stop()