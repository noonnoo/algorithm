class Solution:
    def grayCode(self, n: int) -> List[int]:
        def xor(b1, b2):        #str xor 하기위한 함수
            if b1 == b2: return '0'
            else: return '1'
            
        gray = []        
        for i in range(2 ** n):
            binary = format(i, 'b') 
            while(len(binary) != n):
                binary = '0' + binary
            tmp = binary
            for i in range(1, len(binary)):
                tmp = tmp[:i] + xor(binary[i], binary[i-1]) + tmp[i + 1:]
            gray.append(int(tmp, 2))
                    
        return gray
