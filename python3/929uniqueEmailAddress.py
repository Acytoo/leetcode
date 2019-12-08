class Solution:
    def numUniqueEmails(self, emails):
        my_set = set()
        for email in emails:
            localname, domain = email.split("@")
            localname = localname.replace('.', '')
            localname = localname.split("+")[0]
            my_set.add(localname+"@"+domain)
        return len(my_set)


if __name__ == '__main__':
    s = Solution()
    a = ["a.sd+name@1.com", "df@2.com"]
    print(s.numUniqueEmails(a))
