public class Solution
{
    public string OrderlyQueue(string s, int k)
    {
        int n = s.Length;

        if (k > 1)
        {
            var arr = s.ToCharArray();
            Array.Sort(arr);                 // sort characters ascending
            return new string(arr);
        }

        // k == 1 → best (lexicographically smallest) rotation
        string result = s;
        for (int l = 1; l < n; l++)
        {
            string temp = s.Substring(l) + s.Substring(0, l);
            if (string.CompareOrdinal(temp, result) < 0)
                result = temp;
        }
        return result;
    }
}
