import re
import sys


def main():
    print(convert(input("Hours: ")))


def convert(s):
    match = re.search(r'^(\d?\d{1}):*(\d?\d?) (\w{2})( to )(\d?\d{1}):*(\d?\d?) (\w{2})$', s)
    # Get time
    if match:
        h_start = match.group(1)
        m_start = match.group(2)
        m_a_start = match.group(3)
        h_end = match.group(5)
        m_end = match.group(6)
        m_a_end = match.group(7)
        # 00 in hour is not provided
        if m_start == '':
            m_start = '00'
        if m_end == '':
            m_end = '00'
        # Check if correct input
        if int(h_start) not in range(1,13) or int(h_end) not in range(1,13):
            raise ValueError
        elif int(m_start) not in range(0,60) or int(m_end) not in range(0,60):
            raise ValueError
        else:
        #Concatenate time
            #Start
            #AM
            if m_a_start == 'AM':
                if h_start == '12':
                    time_start = '00:' + m_start
                elif h_start in (10,11):
                    time_start = h_start + ':' + m_start
                else:
                    time_start = '0' + h_start + ':' + m_start
            #PM
            else:
                if h_start == '12':
                    time_start = h_start + ':' + m_start
                else:
                    time_start = str(int(h_start) + 12) + ':' + m_start
            #End
            #AM
            if m_a_end == 'AM':
                if h_end == '12':
                    time_end = '00:' + m_end
                elif h_end in (10,11):
                    time_end = h_end + ':' + m_end
                else:
                    time_end = '0' + h_end + ':' + m_end
            #PM
            else:
                if h_end == '12':
                    time_end = h_end + ':' + m_end
                else:
                    time_end = str(int(h_end) + 12) + ':' + m_end
            time = time_start + ' to ' + time_end
        return time
    else:
        raise ValueError


if __name__ == "__main__":
    main()