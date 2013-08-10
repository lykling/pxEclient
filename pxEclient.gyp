{
  'variables': {
    'project_name': 'pxEclient',
    'version': '1.0.0',
    'conditions': [
      ['OS=="linux"', {
        'use_custom_freetype%': 1,
      }, {
        'use_custom_freetype%': 0,
      }],
    ],
  },
  'targets': [
    {
      'target_name': 'pxEclient',
      'type': 'executable',
      'sources': [
        'src/pxEclientMain.cc',
        'src/option.cc',
        'src/option.h',
        'src/packet.cc',
        'src/packet.h',
        'src/auth.cc',
        'src/auth.h',
      ],
    },
    {
      'target_name': 'pxEclientUnitTest',
      'type': 'executable',
      'sources': [
        'src/util.h',
        'src/util.cc',
        'src/unittest.cc',
      ],
  ],
}
