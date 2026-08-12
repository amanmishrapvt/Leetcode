impl Solution {
    pub fn day_of_year(date: String) -> i32 {
        let days_of_months = [31,28,31,30,31,30,31,31,30,31,30,31];
        let mut result = 0;

        let parts: Vec<&str> = date.split('-').collect();

        let my_int_year = parts[0].parse::<i32>().unwrap();

        let my_int_month = parts[1].parse::<i32>().unwrap();

        let my_int_day = parts[2].parse::<i32>().unwrap();

        if my_int_year % 400 == 0 || (my_int_year % 4 == 0 && my_int_year % 100 != 0) {
            for days in 0..(my_int_month - 1) {
                result += days_of_months[days as usize];
            }

            if my_int_month > 2 {
                result = result + 1;
            }
            result = result + my_int_day;
        }
        else {
            for days in 0..(my_int_month - 1) {
                result += days_of_months[days as usize];
            }
            result = result + my_int_day;
        }
        result
    }
}