SET SERVEROUTPUT ON

-- Declare variables
DECLARE
  a NUMBER;   -- Variable to hold the first Fibonacci number
  b NUMBER;   -- Variable to hold the second Fibonacci number
  c NUMBER;   -- Variable to hold the sum of a and b (next Fibonacci number)
  n NUMBER;   -- The number of Fibonacci numbers to generate
  i NUMBER;   -- Loop counter
BEGIN
  n := 8;     -- Set the number of Fibonacci numbers to generate

  a := 0;     -- Initialize the first Fibonacci number
  b := 1;     -- Initialize the second Fibonacci number

  -- Print the first two Fibonacci numbers
  DBMS_OUTPUT.PUT_LINE(a);
  DBMS_OUTPUT.PUT_LINE(b);

  -- Loop to generate and print Fibonacci numbers
  FOR i IN 1..n-2 LOOP
    c := a + b;  -- Calculate the next Fibonacci number
    DBMS_OUTPUT.PUT_LINE(c);  -- Print the next Fibonacci number

    a := b;       -- Update the first Fibonacci number for the next iteration
    b := c;       -- Update the second Fibonacci number for the next iteration
  END LOOP;
END;
/
