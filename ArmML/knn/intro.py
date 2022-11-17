import math

movieData = {
    "hello": [21, 6, 51, '喜剧'],
    "你好": [11, 5, 15, '喜剧'],
    "lei_hou": [13, 23, 17, '动作'],
    "啊吧": [51, 17, 21, '动作'],
    "歪比": [42, 1, 21, '动作'],
}

testData = [23, 3, 27]
KNN = []
for key, values in movieData.items():
    l1 = math.sqrt((testData[0]-values[0]) ** 2 + (testData[1]-values[1]) ** 2 + (testData[2]-values[2]) ** 2)
    l2 = abs(testData[0]-values[0]) + abs(testData[1]-values[1]) + abs(testData[2]-values[2])
    KNN.append([key, round(l1, l2)])

KNN.sort(key=lambda dis: dis[1])
print(KNN)
