-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find report of the crime
SELECT id, description FROM crime_scene_reports WHERE day = 28 AND month = 7 AND street = "Humphrey Street";
--DESCOBERTA 10:15am in the Humphrey Street bakery, 3 witnesses citing the bakery, id 295

--See what the witnesses saw
SELECT transcript FROM interviews WHERE day = 28 AND month = 7 AND year = 2021;
--DESCOBERTA
--LIly bakery owner -> PHONE for about one hour (9:00)
--EUGENE flight in 29, other person buy the tickets
--RUTH seen in ATM Leggett before the theft
--BARBARA took one car in the parkin lot of the bakery just after the robery

--SEE the lincense plates just after the theft (10:15+)
SELECT activity, license_plate, hour, minute FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021;

--Tring to find a cell phone
SELECT caller, id, receiver, duration FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021 ORDER BY duration;
SELECT caller, receiver, duration FROM phone_calls GROUP BY caller, receiver  HAVING COUNT(*) > 1;
-- (389) 555-5198 SUSPECT,

SELECT name, id, phone_number, passport_number, license_plate FROM people WHERE phone_number LIKE "(389)%";
--LUCA 467400 (389) 55-5198 8496433585 4328GD8, Car exit bakery at 10:19
--WALTER 358382 (544) 555-8087 4223654265 82456Y8, Called Luca for abaut 1 hour
--Kathryn 561160 (609) 555 - 5876 6121106406 4ZY7I8T, Called Luca for one minute


--DOrothy 720244 (047) 555- 0577 9135709773 7T807V5


--(544) 555-8087 (609) 555 - 5876


SELECT name FROM people JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate WHERE day = "28" AND month = "7" AND year = "2021" AND hour = "10" AND minute >= "15" AND hour < "11" AND activity = "exit"
-- Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana, Kelsey, Taylor.

SELECT DISTINCT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number WHERE day = "28" AND month = "7" AND year = "2021" AND transaction_type = "withdraw" AND atm_location LIKE "%Leggett%%"
-- Luca Taylor Bruce Iman Diana

SELECT name FROM people JOIN passengers ON people.passport_number = passengers.passport_number WHERE flight_id = ( SELECT id FROM flights WHERE day = "29" AND month = "7" AND year = "2021" ORDER BY hour, minute LIMIT 1)
--Bruce Taylor Luca

SELECT DISTINCT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.caller WHERE day = "28" AND month = "7" AND year = "2021" AND duration < "60"
--Taylor Bruce

SELECT city FROM airports WHERE id = ( SELECT destination_airport_id FROM flights WHERE day = "29" AND month = "7" AND year = "2021" ORDER BY hour, minute)

SELECT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.receiver WHERE day = "28" AND month = "7" AND year = "2021" AND duration < "60" AND caller = ( SELECT phone_number FROM people WHERE name = "Taylor")