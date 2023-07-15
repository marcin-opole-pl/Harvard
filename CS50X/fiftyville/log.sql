-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Check what's inside crime_scene_reports
SELECT *
    FROM crime_scene_reports;
-- Look for Humprey Street on 28/07/2021 in crime_scene_reports
SELECT *
    FROM crime_scene_reports
  WHERE year = "2021"
    AND month = "7"
    AND day = "28";
        -->> Theft took place on 10:15 am at Humprey Street bakery. Three witnesses were interviewed.
-- Look for interview transcripts
SELECT *
    FROM interviews
  WHERE year = "2021"
    AND month = "7"
    AND day = "28";
        -->> Ruth said: Within 10 minutes from theft, thief drove away -->> Check bakery CCTV
        -->> Eugene said: In the morning thief withdrawn money from ATM at Leggett Street -->> Check ATM transactions
        -->> Raymond said: As thief left bakery, he called someone and talked for less then a minute,
        -->> and said he was plannnig to take earliest flight out of Fiftyville on 29/07/2021, and asked accomplice to tickets -->> Check flights
-- Check bakery CCTV
SELECT *
    FROM bakery_security_logs
  WHERE year = "2021"
    AND month = "7"
    AND day = "28"
    AND hour = "10"
    AND minute BETWEEN 15 AND 25;
-- Search for suspects by license plates
SELECT name, phone_number, passport_number
    FROM people
    WHERE license_plate IN (
        SELECT license_plate
            FROM bakery_security_logs
          WHERE year = "2021"
            AND month = "7"
            AND day = "28"
            AND hour = "10"
            AND minute BETWEEN 15 AND 25
        );
        -->>    +---------+----------------+-----------------+
                |  name   |  phone_number  | passport_number |
                +---------+----------------+-----------------+
                | Vanessa | (725) 555-4692 | 2963008352      |
                | Barry   | (301) 555-4174 | 7526138472      |
                | Iman    | (829) 555-5269 | 7049073643      |
                | Sofia   | (130) 555-0289 | 1695452385      |
                | Luca    | (389) 555-5198 | 8496433585      |
                | Diana   | (770) 555-1861 | 3592750733      |
                | Kelsey  | (499) 555-9472 | 8294398571      |
                | Bruce   | (367) 555-5533 | 5773159633      |
                +---------+----------------+-----------------+
-- Search for suspects by ATM transactions
SELECT name, amount
    FROM people
    JOIN bank_accounts
    ON person_id = people.id
    JOIN atm_transactions
    ON atm_transactions.account_number = bank_accounts.account_number
  WHERE year = "2021"
    AND month = "7"
    AND day = "28"
    AND atm_location LIKE "Leggett Street"
    AND transaction_type = "withdraw";
          -->>    +---------+--------+
                  |  name   | amount |
                  +---------+--------+
                  | Bruce   | 50     |
                  | Diana   | 35     |
                  | Brooke  | 80     |
                  | Kenny   | 20     |
                  | Iman    | 20     |
                  | Luca    | 48     |
                  | Taylor  | 60     |
                  | Benista | 30     |
                  +---------+--------+
-- Search for suspects by phonecalls
SELECT name, caller
    FROM people
    JOIN phone_calls
    ON caller = people.phone_number
  WHERE year = "2021"
    AND month = "7"
    AND day = "28"
    AND duration < 60;
      -->>    +---------+----------------+
              |  name   |     caller     |
              +---------+----------------+
              | Sofia   | (130) 555-0289 |
              | Kelsey  | (499) 555-9472 |
              | Bruce   | (367) 555-5533 |
              | Kelsey  | (499) 555-9472 |
              | Taylor  | (286) 555-6063 |
              | Diana   | (770) 555-1861 |
              | Carina  | (031) 555-6622 |
              | Kenny   | (826) 555-1652 |
              | Benista | (338) 555-6650 |
              +---------+----------------+
SELECT name, receiver
    FROM people
    JOIN phone_calls
    ON receiver = people.phone_number
  WHERE year = "2021"
    AND month = "7"
    AND day = "28"
    AND duration < 60;
      -->>    +------------+----------------+
              |    name    |    receiver    |
              +------------+----------------+
              | Jack       | (996) 555-8899 |
              | Larry      | (892) 555-8872 |
              | Robin      | (375) 555-8161 |
              | Melissa    | (717) 555-1342 |
              | James      | (676) 555-6554 |
              | Philip     | (725) 555-3243 |
              | Jacqueline | (910) 555-3251 |
              | Doris      | (066) 555-9701 |
              | Anna       | (704) 555-2131 |
              +------------+----------------+
-- Search for suspects by flights
SELECT flights.id AS flight_id, full_name AS destination, city, hour, minute
    FROM airports
    JOIN flights
    ON destination_airport_id = airports.id
  WHERE year = "2021"
    AND month = "7"
    AND day = "29"
    ORDER BY hour;
      -->>    +-----------+-------------------------------------+---------------+------+--------+
              | flight_id |             destination             |     city      | hour | minute |
              +-----------+-------------------------------------+---------------+------+--------+
              | 36        | LaGuardia Airport                   | New York City | 8    | 20     |
              | 43        | O Hare International Airport        | Chicago       | 9    | 30     |
              | 23        | San Francisco International Airport | San Francisco | 12   | 15     |
              | 53        | Tokyo International Airport         | Tokyo         | 15   | 20     |
              | 18        | Logan International Airport         | Boston        | 16   | 0      |
              +-----------+-------------------------------------+---------------+------+--------+--+
SELECT name AS passenger
    FROM people
    JOIN passengers
    ON passengers.passport_number = people.passport_number
  WHERE flight_id = 36;
        -->>  +-----------+
              | passenger |
              +-----------+
              | Doris     |
              | Sofia     |
              | Bruce     |
              | Edward    |
              | Kelsey    |
              | Taylor    |
              | Kenny     |
              | Luca      |
              +-----------+
