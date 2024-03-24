import os
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


def DocDuLieu():
    folder_path = "data/output2"
    X = []
    Y = []
    for filename in os.listdir(folder_path):
        if filename.endswith(".csv"):
            # Xây dựng đường dẫn tới từng file CSV
            file_path = os.path.join(folder_path, filename)
            filename = filename.split('.')[0][:2]

            # gán dữ liệu vào biến
            df = pd.read_csv(file_path)
            df = df.drop(labels="STT", axis=1)
            X.append(df.values)
            if filename == "AN":
                # trang thai kho tho gan nhãn = 1
                Y.append(1)
            elif filename == "NM":
                # trang thai binh thuong
                Y.append(0)
    return (np.array(X), np.array(Y))

def DocDuLieuNgungThoVaTho():
    folder_path = "data/output2"
    NT = []
    T = []
    for filename in os.listdir(folder_path):
        if filename.endswith(".csv"):
            # Xây dựng đường dẫn tới từng file CSV
            file_path = os.path.join(folder_path, filename)
            filename = filename.split('.')[0][:2]

            # gán dữ liệu vào biến
            df = pd.read_csv(file_path)
            df = df.drop(labels="STT", axis=1)

            if filename == "AN":
                # trang thai kho tho gan nhãn = 1
                NT.append(df.values)
            elif filename == "NM":
                # trang thai binh thuong
                T.append(df.values)

    return (np.array(NT), np.array(T))

def ChuyenDoiTatCaDuLieuTuHangSangCot_AllFile(df):
    X_after = []
    for arr1 in df:
        sample_after = np.array([arr1[:, 0], arr1[:, 1], arr1[:, 2], arr1[:, 3], arr1[:, 4], arr1[:, 5]])
        X_after.append(sample_after)
    return np.array(X_after)

def TinhTanSoFourierCuaMang(arr1):
    arr1 = arr1 - np.mean(arr1)
    F = np.fft.fft(arr1)
    amplitude = np.abs(F)
    return amplitude

def TinhTanSoXuatHienCaoNhatTrongMang(arr1):
    amplitude = TinhTanSoFourierCuaMang(arr1)
    return np.argmax(amplitude)

def PlotArr1(arr1):
    plt.plot(arr1)
    plt.show()

if __name__ == "__main__":
    X, Y = DocDuLieu()
    X_ = ChuyenDoiTatCaDuLieuTuHangSangCot_AllFile(X)

    print(X.shape)
    print(X_.shape)
