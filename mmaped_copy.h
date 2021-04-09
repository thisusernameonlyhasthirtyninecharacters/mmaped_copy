#pragma once

#include <algorithm>
#include <type_traits>
#include <unordered_map>
#include <functional>

#include <filesystem>
#include <exception>

#include <string>

#include <fstream>


namespace N
{
	struct input_file_exist : public std::exception
	{
		const char* what() const noexcept override
		{
			return "Input file doesn't exist.";
		}
	};

	struct regular_file : public std::exception
	{
		const char* what() const noexcept override
		{
			return "File is not a regular file.";
		}
	};

	struct output_file_create : public std::exception
	{
		const char* what() const noexcept override
		{
			return "Not able to create output file.";
		}
	};


	// helper enum
	enum class rounding_fn
	{
		floor,
		ceil
	};

	template<typename T = uint64_t>
	concept req = std::is_integral_v<T> && std::is_unsigned_v<T>;
	template<req T>
	struct F
	{

		T number_bytes{ 0 };				// number of bytes to copy

		T original_offset{ 0 };				// original byte offset
		mutable T aligned_offset{ 0 };				// aligned byte offset

		std::filesystem::path finput_path;			// path to input file
		std::filesystem::path foutput_path;			// path to output file
		

		T finput_size{ 0 };					// size in bytes of input file
		T foutput_size{ 0 };				// size in bytes of output file

		int finput_descriptor{ 0 };			// input file descriptor
		int foutput_descriptor{ 0 };		// output file descriptor


		explicit F(std::string input_file, std::string output_file, T offset = 0, T bytes = 0)
			: finput_path{ std::move(input_file) }, foutput_path{ std::move(output_file) }, original_offset{ offset }, number_bytes{ bytes }
		{

			if (not std::filesystem::is_regular_file(finput_path))
			{
				if (not std::filesystem::exists(finput_path))
				{
					throw N::input_file_exist();
				}

				throw N::regular_file();
			}


			if (not std::filesystem::exists(foutput_path))
			{
				std::fstream output_file_s(foutput_path, std::fstream::out);
				
				if (!output_file_s)
				{
					throw N::output_file_create();
				}

				output_file_s.close();
			}
			else
			{
				if (not std::filesystem::is_regular_file(foutput_path))
				{
					throw N::regular_file();
				}
			}
		}





		auto calculate_offset(rounding_fn round_mode = rounding_fn::floor, T ratio = 512) const -> T
		{
			const auto rounding_fn = [round_mode](auto val)
			{
				switch (round_mode)
				{
				case rounding_fn::floor: return std::floor(val);
				case rounding_fn::ceil: return std::ceil(val);
				default: return std::floor(val); // here to disable warning, will never reach
				}
			};

			if (this->original_offset % ratio) {
				this->aligned_offset =
					static_cast<T>(rounding_fn(static_cast<double>(original_offset) / ratio) * ratio);
			}
			else {
				aligned_offset = original_offset;
			}
			return aligned_offset;
		}





		// função que abre o ficheiro e o mapeia na memoria

		//auto fmmap(T a = )-> void



	private:

		struct mdeleter;

// mover isto para fora do construtor para poder usar referencias na struct para as variaveis
// com o tamanho que vai ser mapeado.
//mmaped_finput	= { nullptr, mdeleter{finput_size} };
//mmaped_foutput	= { nullptr, mdeleter{foutput_size} };

		std::unique_ptr<char, mdeleter> mmaped_finput = { nullptr, mdeleter{finput_size} };
		std::unique_ptr<char, mdeleter> mmaped_foutput = { nullptr, mdeleter{foutput_size} };

		struct mdeleter
		{
			T & input_size;

			void operator() (char* ptr) const
			{
				//if (input_size != 0) ::munmap(ptr, input_size);
			}

		};


	};


}

/*
		template<typename FloatT, typename Function = FloatT(*)(FloatT)>
		requires
			(std::is_same_v<FloatT, long double> || std::is_same_v<FloatT, double>)
			&& std::is_invocable_r_v<FloatT, Function, FloatT>
			[[deprecated("Allows standard function for function pointer assignment, but it's UB."
				" Use calculate_offset(rounding, T) instead.")]]
		auto deprecated_calculate_offset(const Function& f, T ratio = 512) -> T
		{
			if (this->original_offset % ratio) {
				this->aligned_offset =
					static_cast<T>(std::invoke(f, (static_cast<FloatT>(original_offset) / ratio))) * ratio;
			}
			else {
				aligned_offset = original_offset;
			}
			return aligned_offset;
		}
*/