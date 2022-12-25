from collections import OrderedDict

_ans = {}

while True:
    try:
        _set = input()
        _set = eval(_set)
        for index in _set:
            if not _ans.get(index):
                _ans[index] = _set[index]
            else:
                _ans[index] = _ans[index] + _set[index]
    except EOFError:
        break

_ans = OrderedDict(sorted(_ans.items()))
for k in _ans:
    print(k + ":" + _ans[k])
