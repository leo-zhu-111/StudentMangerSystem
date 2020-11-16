import os
import requests
import random
from multiprocessing.pool import ThreadPool
from tqdm import tqdm

header = {
    'origin': 'https://www.pianku.tv',
    'referer': 'https://www.pianku.tv/py/lJWMpVmYqRWb_1.html?158064',
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/81.0.4044.138 Safari/537.36 Edg/81.0.416.72'
}
proxies = ['HTTP://110.243.30.23:9999', 'HTTP://222.189.191.206:9999', 'HTTP://118.212.104.138:9999',
           'HTTP://182.149.83.97:9999', 'HTTP://106.42.163.100:9999', 'HTTP://120.83.107.69:9999',
           'HTTP://60.13.42.135:9999', 'HTTP://60.205.188.24:3128', 'HTTP://113.195.232.23:9999',
           'HTTP://59.62.36.74:9000', 'HTTP://218.2.226.42:80']
proxy = {'HTTP': random.choice(proxies)}
print(proxy)
path = './Spider/'

if os.path.exists(path + "天气之子/"):
    pass
else:
    os.makedirs(path + "天气之子/")

failure_list = []  # 保存下载失败的片段

def download(num, flag=0):
    # https://*****/20200508/19312_c9d456ff/1000k/hls/d3276cb1804001613.ts
    url = 'https://*****/20200508/19312_c9d456ff/1000k/hls/d3276cb180400{:0>4d}.ts'.format(num)
    with open(path + "天气之子/" + str(url).split('/')[-1][-7:], 'wb') as f:
        try:
            r = requests.get(url, proxies=proxy, headers=header, timeout=5)
            r.raise_for_status()
            r.encoding = 'utf-8'
            print('正在下载第 {} 个片段。'.format(num))
            f.write(r.content)
            if flag == 1:
                failure_list.remove(num)
        except:
            print('请求失败！')
            if num not in failure_list:
                failure_list.append(num)

def get_video():
    files = os.listdir(path + "天气之子/")
    for file in tqdm(files, desc="正在转换视频格式："):
        if os.path.exists(path + "天气之子/" + file):
            with open(path + "天气之子/" + file, 'rb') as f1:
                with open(path + "天气之子.mp4", 'ab') as f2:
                    f2.write(f1.read())
        else:
            print("失败")

def check_ts():
    print("开始检查：")
    while failure_list:
        for num in failure_list:
            download(num, 1)
    print("ts 文件下载完成！")
    get_video()


if __name__ == '__main__':
    # 开启线程池
    pool = ThreadPool(100)
    results = pool.map(download, range(1, 1613+1))
    pool.close()
    pool.join()
