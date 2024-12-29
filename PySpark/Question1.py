from pyspark.sql import SparkSession
from pyspark.sql.functions import col

# Step 1: Create a Spark session
spark = SparkSession.builder.appName("DataFrame Operations").getOrCreate()

# Step 2: Create a DataFrame with four columns: "name", "age", "city", and "gender"
data = [
    ("Alice", 28, "New York", "Female"),
    ("Bob", 35, "Los Angeles", "Male"),
    ("Cathy", 40, "Chicago", "Female"),
    ("David", 22, "Houston", "Male"),
    ("Ella", 31, "Phoenix", "Female"),
    ("Frank", 29, "Seattle", "Male"),
    ("Grace", 33, "Denver", "Female"),
    ("Hank", 25, "Boston", "Male"),
    ("Ivy", 37, "San Diego", "Female"),
    ("Jack", 45, "Austin", "Male")
]
columns = ["name", "age", "city", "gender"]
df = spark.createDataFrame(data, columns)

print("Initial DataFrame:")
df.show()

# Step 3: Filter rows with age greater than 30
df_filtered = df.filter(col("age") > 30)
print("DataFrame after filtering rows where age > 30:")
df_filtered.show()

# Step 4: Add a new column named "tax" (for example, a constant value for demonstration)
df_with_tax = df.withColumn("tax", col("age") * 0.1)
print("DataFrame after adding the 'tax' column:")
df_with_tax.show()

# Step 5: Rename the "age" column to "years"
df_renamed = df_with_tax.withColumnRenamed("age", "years")
print("DataFrame after renaming 'age' to 'years':")
df_renamed.show()

# Step 6: Drop multiple columns (e.g., drop "city" and "gender")
df_final = df_renamed.drop("city", "gender")
print("DataFrame after dropping 'city' and 'gender' columns:")
df_final.show()

# Stop the Spark session
spark.stop()
