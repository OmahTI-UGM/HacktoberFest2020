/* This algorithm is the same as SCAN algorithm
 * So there will be similar code 
 * (In fact, I just copied the SCAN and made
 * improvements to meet Circular LOOK algorithm requirements)
**/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float avg;
    int sectors[100], head, n_sectors, totalSeek, count=0, found=0;

    // I put this code here because I found strange
    // behavior of my code. It marked sectors 68, 72, 83 out of the blue.
    for (int i = 0; i < 100; i++)
    {
        sectors[i] = 0;
    }
    

    cout << " *** Circular Look Disk Management Algorithm ***\n" << endl;
    
    // In os sim the total of sectors is 192 sectors,
    // within 16 cylinders in which has 12 sectors each.
    // Here, I use only 100 sectors just to simulate the algorithm.
    cout << "Total of available sectors = 100" << endl;
    
    // The total of sectors that will be served
    cout << "Enter number of sectors: ";
    cin >> n_sectors;

    // The sectors that will be served
    cout << "Enter the sectors:" << endl;
    for (int i = 0; i < n_sectors; i++)
    {
        int sector;
        cout << "Input sector: ";
        cin >> sector;

        // Mark the sector location
        sectors[sector] = 1;
    }

    // Prints the sectors
    cout << "[ ";
    for (int i = 0; i < 100; i++)
    {
        if(sectors[i] == 1)
        cout << i << " ";
    }
    cout << "]" << endl;
    

    // The position of the head which the disk will be started from
    cout << "Enter head position: ";
    cin >> head;

    // The algorithm is running from head position,
    // scanning through the disk until the end of sectors,
    // then start over from beginning of disk sector,
    // scanning until the last sector to be served.
    for (int i = 0; i < 100; i++)
    {
        if (head > 99)
        {
            head = 0;
        }
        if (sectors[head] == 1)
        {
            found++;
            sectors[head] = 2;
            if (count == 1)
            {
                cout << "Seek " << count << "\ttime from last sector. Current sector number: " << (head) << endl;
            }
            else
            {
                cout << "Seek " << count << "\ttimes from last sector. Current sector number: " << (head) << endl;
            }
            totalSeek += count;

            // Reset the count so it can calculate the seek time
            // between this sector and the next sector found.
            count = 0;

            // Break whenever the number of found sectors
            // equals the total sectors to be served.
            if(found == n_sectors) break;
        }
        head++;
        count++;
    }

    cout << "Total seek time until last sector served is: " << totalSeek << endl;
    avg = totalSeek/(float)n_sectors;
    cout << "Average seek time is: " << avg << endl;

    return 0;
}
