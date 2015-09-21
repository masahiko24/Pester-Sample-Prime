Import-Module Pester.psm1

$scriptPath = $MyInvocation.MyCommand.Path
$homePath = Split-Path $scriptPath -Parent
$exePath = Join-Path $homePath "Release\Primes.exe"

Describe "Primes" {
    
    Context "-leの場合" {
        
        It "10以下の素数を求めるテスト" {
            $psi = New-Object Diagnostics.ProcessStartInfo($exePath, @("-le", 10))
            $psi.RedirectStandardOutput = $true
            $psi.UseShellExecute = $false
            $process = [Diagnostics.Process]::Start($psi)
            $process.WaitForExit()
            $process.StandardOutput.ReadToEnd() | Should Be "[ 2 3 5 7 ]`r`n" 
            $process.ExitCode | Should Be 0
        }

    }

    Context "-atの場合" {

        It "100番目の素数を求めるテスト" {
            $psi = New-Object Diagnostics.ProcessStartInfo($exePath, @("-at", 100))
            $psi.RedirectStandardOutput = $true
            $psi.UseShellExecute = $false
            $process = [Diagnostics.Process]::Start($psi)
            $process.WaitForExit()
            $process.StandardOutput.ReadToEnd() | Should Be "541`r`n" 
            $process.ExitCode | Should Be 0
        }

    }

    Context "不正な入力の場合" {

        It "引数を与えないテスト" {
            $psi = New-Object Diagnostics.ProcessStartInfo($exePath, @())
            $psi.RedirectStandardOutput = $true
            $psi.UseShellExecute = $false
            $process = [Diagnostics.Process]::Start($psi)
            $process.WaitForExit()
            $process.ExitCode | Should Be 1
        }

        It "-leのみ指定するテスト" {
            $psi = New-Object Diagnostics.ProcessStartInfo($exePath, @("-le"))
            $psi.RedirectStandardOutput = $true
            $psi.UseShellExecute = $false
            $process = [Diagnostics.Process]::Start($psi)
            $process.WaitForExit()
            $process.ExitCode | Should Be 1
        }

        It "-atのみ指定するテスト" {
            $psi = New-Object Diagnostics.ProcessStartInfo($exePath, @("-at"))
            $psi.RedirectStandardOutput = $true
            $psi.UseShellExecute = $false
            $process = [Diagnostics.Process]::Start($psi)
            $process.WaitForExit()
            $process.ExitCode | Should Be 1
        }

        It "数値のみ指定するテスト" {
            $psi = New-Object Diagnostics.ProcessStartInfo($exePath, @("100"))
            $psi.RedirectStandardOutput = $true
            $psi.UseShellExecute = $false
            $process = [Diagnostics.Process]::Start($psi)
            $process.WaitForExit()
            $process.ExitCode | Should Be 1
        }

        It "-leと数値を2つ指定するテスト" {
            $psi = New-Object Diagnostics.ProcessStartInfo($exePath, @("-le", 10, 20))
            $psi.RedirectStandardOutput = $true
            $psi.UseShellExecute = $false
            $process = [Diagnostics.Process]::Start($psi)
            $process.WaitForExit()
            $process.ExitCode | Should Be 1
        }

        It "-atと数値を2つ指定するテスト" {
            $psi = New-Object Diagnostics.ProcessStartInfo($exePath, @("-at", 10, 20))
            $psi.RedirectStandardOutput = $true
            $psi.UseShellExecute = $false
            $process = [Diagnostics.Process]::Start($psi)
            $process.WaitForExit()
            $process.ExitCode | Should Be 1
        }

    }

}
