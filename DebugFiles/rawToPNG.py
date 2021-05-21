
from PIL import Image

def convert(name):
    with open(name + '.bin', 'rb') as f:
        data = f.read()

    im = Image.frombytes('RGBA', (1280, 720), data)
    im.save(name + '.png')

convert('layer0_tex')
convert('reveal_masks')
