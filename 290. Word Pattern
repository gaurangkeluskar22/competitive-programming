class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        str_data=list(str.strip().split())
        print(str_data)
        pattern_data=[]
        for i in pattern:
            pattern_data.append(i)
        if(len(pattern_data)>len(str_data) or len(str_data)>len(pattern_data)):
            return False
        else:
            
            dic={}
            dic[pattern_data[0]]=str_data[0]

            for i in range(1,len(pattern_data)):
                if(pattern_data[i] in dic):
                    if(dic[pattern_data[i]]!=str_data[i]):
                        return False
                else:
                    data=dic.values()
                    if(str_data[i] in data):
                        return False
                    else:
                        dic[pattern_data[i]]=str_data[i]

            return True
