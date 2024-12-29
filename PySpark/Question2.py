from pyspark.sql import SparkSession
from pyspark.sql.functions import col, sum

# Create a Spark session
spark = SparkSession.builder.appName("Question - 2").getOrCreate()

data = [
    (101, "Laptop", "Electronics", 700, 10, 4.5),
    (102, "Smartphone", "Electronics", 500, 20, 4.3),
    (103, "Tablet", "Electronics", 300, 15, 4.1),
    (201, "Chair", "Furniture", 50, 50, 4.0),
    (202, "Table", "Furniture", 150, 30, 4.2),
    (203, "Couch", "Furniture", 500, 10, 4.6),
    (301, "Shampoo", "Personal Care", 10, 100, 4.3),
    (302, "Soap", "Personal Care", 5, 200, 4.4),
    (303, "Toothpaste", "Personal Care", 2, 300, 4.1),
    (401, "T-shirt", "Apparel", 20, 50, 4.2),
]

columns = ["ProductID", "ProductName", "Category", "Price",
"StockQuantity", "Rating"]

# Create dataframe
df = spark.createDataFrame(data, columns)

# Sort the DataFrame first by Price in descending order and then by Category in ascending order
sorted_df = df.orderBy(col("Price").desc(), col("Category").asc())

# 2. Calculate the total sales amount for each product by category
sales_df = df.withColumn("TotalSales", col("Price") *
col("StockQuantity"))

category_sales_df = sales_df.groupBy("Category").agg(sum("TotalSales"))

# 3. Total sales amount and the total quantity sold for each product.
product_sales_df = sorted_df.groupBy("ProductID", "ProductName").agg(sum("TotalSales"),sum("StockQuantity"))

# Show results for each step
print("Original DataFrame:")
df.show()
print("Sorted DataFrame (by Price desc, then Category asc):")
sorted_df.show()
print("Total Sales Amount by Category:")
category_sales_df.show()
print("Total Sales Amount and Quantity Sold by Product:")
product_sales_df.show()
# Stop SparkSession
spark.stop()