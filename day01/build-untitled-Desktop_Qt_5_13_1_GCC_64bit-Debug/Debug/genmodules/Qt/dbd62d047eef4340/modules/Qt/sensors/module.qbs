import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Sensors"
    Depends { name: "Qt"; submodules: ["core"]}

    architectures: ["x86_64"]
    targetPlatform: "linux"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: ["/home/a/Qt5.13.1/5.13.1/gcc_64/lib/libQt5Core.so","Qt5Core;-lpthread;"]
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5Sensors"
    libNameForLinkerRelease: "Qt5Sensors"
    libFilePathDebug: undefined
    libFilePathRelease: "/home/a/Qt5.13.1/5.13.1/gcc_64/lib/libQt5Sensors.so.5.13.1"
    pluginTypes: ["sensors","sensorgestures"]
    moduleConfig: ["lex","yacc","depend_includepath","testcase_targets","import_plugins","import_qpa_plugin","qt_build_extra","file_copies","qmake_use","qt","warn_on","release","link_prl","incremental","shared","release","linux","unix","posix","gcc","sse2","aesni","sse3","ssse3","sse4_1","sse4_2","avx","avx2","avx512f","avx512bw","avx512cd","avx512dq","avx512er","avx512ifma","avx512pf","avx512vbmi","avx512vl","compile_examples","enable_new_dtags","f16c","force_debug_info","largefile","precompile_header","rdrnd","shani","x86SimdAlways","prefix_build","force_independent","utf8_source","create_prl","link_prl","prepare_docs","qt_docs_targets","no_private_qt_headers_warning","QTDIR_build","qt_example_installs","exceptions_off","testcase_exceptions","explicitlib","strict_flags","generated_privates","relative_qt_rpath","git_build","qmake_cache","target_qt","c++11","strict_c++","c++14","c99","c11","hide_symbols","bsymbolic_functions","separate_debug_info","qt_install_headers","need_fwd_pri","qt_install_module","create_cmake","compiler_supports_fpmath","create_pc","create_libtool","have_target","dll","debug_info","thread","moc","resources"]
    cpp.defines: ["QT_SENSORS_LIB"]
    cpp.includePaths: ["/home/a/Qt5.13.1/5.13.1/gcc_64/include","/home/a/Qt5.13.1/5.13.1/gcc_64/include/QtSensors"]
    cpp.libraryPaths: ["/home/qt/openssl-1.1.1b/lib"]
    Group {
        files: [Qt["sensors"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary"]
    }
}
