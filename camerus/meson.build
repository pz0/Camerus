project(
    'camerus', 
    'cpp', 
    default_options : [
        'cpp_std=c++2a'
    ]
)

src = [
    'main.cpp',
    'core/video_reader.h'
]

opencv = dependency('opencv4')

executable(
    'camerus', 
    sources : src,
    dependencies : opencv,
    link_args: ['-lpthread' ,'-ljpeg', '-lrt' ,'-pthread']
)