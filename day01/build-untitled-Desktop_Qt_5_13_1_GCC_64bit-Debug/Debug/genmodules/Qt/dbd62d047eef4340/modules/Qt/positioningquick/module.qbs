import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "PositioningQuick"
    Depends { name: "Qt"; submodules: ["quick","positioning","qml","core"]}

    architectures: ["x86_64"]
    targetPlatform: "linux"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: ["/home/a/Qt5.13.1/5.13.1/gcc_64/lib/libQt5Positioning.so","/home/a/Qt5.13.1/5.13.1/gcc_64/lib/libQt5Quick.so"]
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5PositioningQuick"
    libNameForLinkerRelease: "Qt5PositioningQuick"
    libFilePathDebug: undefined
    libFilePathRelease: "/home/a/Qt5.13.1/5.13.1/gcc_64/lib/libQt5PositioningQuick.so.5.13.1"
    pluginTypes: []
    moduleConfig: ["lex","yacc","depend_includepath","testcase_targets","import_plugins","import_qpa_plugin","qt_build_extra","file_copies","qmake_use","qt","warn_on","release","link_prl","incremental","shared","release","linux","unix","posix","gcc","sse2","aesni","sse3","ssse3","sse4_1","sse4_2","avx","avx2","avx512f","avx512bw","avx512cd","avx512dq","avx512er","avx512ifma","avx512pf","avx512vbmi","avx512vl","compile_examples","enable_new_dtags","f16c","force_debug_info","largefile","precompile_header","rdrnd","shani","x86SimdAlways","prefix_build","force_independent","utf8_source","create_prl","link_prl","prepare_docs","qt_docs_targets","no_private_qt_headers_warning","QTDIR_build","qt_example_installs","exceptions_off","testcase_exceptions","explicitlib","warning_clean","done_config_gypsy","done_config_winrt","simd","optimize_full","relative_qt_rpath","git_build","qmake_cache","target_qt","c++11","strict_c++","c++14","c99","c11","hide_symbols","bsymbolic_functions","separate_debug_info","qt_install_headers","need_fwd_pri","qt_install_module","create_cmake","compiler_supports_fpmath","create_pc","create_libtool","have_target","dll","debug_info","arch_haswell","avx512common","avx512core","thread","opengl","moc","resources"]
    cpp.defines: ["QT_POSITIONINGQUICK_LIB"]
    cpp.includePaths: ["/home/a/Qt5.13.1/5.13.1/gcc_64/include","/home/a/Qt5.13.1/5.13.1/gcc_64/include/QtPositioningQuick"]
    cpp.libraryPaths: ["/home/qt/openssl-1.1.1b/lib"]
    Group {
        files: [Qt["positioningquick"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary"]
    }
}
