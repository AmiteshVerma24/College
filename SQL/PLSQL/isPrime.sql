SET SERVEROUTPUT ON

-- Declare variables
DECLARE
  n NUMBER := &n;   -- Take user input for n
  j NUMBER := 2;     -- Initialize divisor
  counter NUMBER := 0; -- Initialize counter to track prime status
BEGIN
  -- Loop to check divisibility
  WHILE (j <= n/2) LOOP
    IF MOD(n, j) = 0 THEN
      -- If n is divisible by j, it's not prime
      DBMS_OUTPUT.PUT_LINE(n || ' is not a prime number');
      counter := 1;   -- Mark as not prime
      EXIT;           -- Exit the loop
    ELSE
      j := j + 1;     -- Increment divisor
    END IF;
  END LOOP;

  -- Check counter to determine prime status
  IF counter = 0 THEN
    DBMS_OUTPUT.PUT_LINE(n || ' is a prime number');
  END IF;
END;
/
