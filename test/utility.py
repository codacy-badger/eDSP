import scipy.signal as sp
import numpy as np
from random import randint

def get_generators():
    return [sp.hamming, sp.hann, sp.flattop, sp.nuttall, sp.blackman, sp.parzen]

def generate_inputs(number_inputs, minimum_size, maximum_size):
    signals = get_generators()
    data = []
    for _ in range(number_inputs):
        size = randint(minimum_size, maximum_size)
        data.append(signals[randint(0, len(signals) - 1)](size).astype(np.float64) + 0.1)
    return data

def generate_pair_inputs(number_inputs, minimum_size, maximum_size):
    signals = get_generators()
    first = []
    second = []
    for _ in range(number_inputs):
        size = randint(minimum_size, maximum_size)
        first.append(signals[randint(0, len(signals) - 1)](size).astype(np.float64) + 0.1)
        second.append(signals[randint(0, len(signals) - 1)](size).astype(np.float64) + 0.1)
    return first, second

def generate_timestamps(init_t, n, sr):
    samples = np.zeros(shape=(n,), dtype=np.float64)
    period = 1.0 / sr
    temporal = init_t
    for i in range(n):
        samples[i] = temporal
        temporal = temporal + period
    return samples
